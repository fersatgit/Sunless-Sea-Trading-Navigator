program TradingNavigator;

uses
  Windows,Messages;

function GetUserDefaultUILanguage: dword;stdcall;external kernel32;
function LoadBitmapW(hInstance: HINST; lpBitmapName: PWideChar): THandle; stdcall;external user32;
function wsprintfW(buf,fmt: PWideChar): dword;cdecl;varargs;external user32;

{$R Resources.res}
{$Include Data.inc}
var
  bmi:                                              BITMAPINFO=(bmiheader:(biSize:     sizeof(BITMAPINFOHEADER);
                                                                           biHeight:   56;
                                                                           biPlanes:   1;
                                                                           biBitCount: 32));
  font:                                             tagLOGFONTW=(lfHeight:         16;
                                                                 lfWidth:          6;
                                                                 lfWeight:         500;
                                                                 lfCharSet:        OEM_CHARSET;
                                                                 lfOutPrecision:   OUT_TT_PRECIS;
                                                                 lfQuality:        5;//CLEARTYPE_QUALITY;
                                                                 lfPitchAndFamily: VARIABLE_PITCH;
                                                                 lfFaceName:       ('T','A','H','O','M','A',#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0,#0));
  HDelim:                                           integer=350;
  VDelim:                                           integer=206;
  ItemNames,LocationNames,ShopNames:                array of PWideChar;
  MouseStatus,RoutesCount,RouteLen,RouteListWidth:  dword;
  MaxRouteItemWidth:                                dword;
  defListBoxProc:                                   pointer;
  SizeWE,SizeNS,HighLightBrush,BackBrush:           THandle;
  IconsDC,BackBuf,hFont,hFontSmall:                 THandle;
  ItemList,RouteList,RouteDetail,RadioEng,RadioRus: THandle;
  Routes:                                           array[0..511] of packed record
                                                                    RouteLen:  dword;
                                                                    LoopIndex: integer;
                                                                    Route:     array[0..63] of packed record
                                                                                               LocationID,ShopID,ItemID,Count: word;
                                                                                               end;
                                                                    end;
  UsedItems:                                        set of byte;
  ItemRatios:                                       array[0..length(Items)-1] of single;
  Route:                                            array[0..255] of packed record
                                                                     Location,Shop: byte;
                                                                     Item:          word;
                                                                     end;

procedure FindRoutes(_ItemID,_Amount,_CurAmount: Cardinal);
label
  SaveRoute,continue;
var
  i,j,k,Amount,CurAmount: Cardinal;
  ItemRatio:              single;
begin
  Route[RouteLen].Item:=_ItemID;
  include(UsedItems,_ItemID);
  inc(RouteLen);
  for i:=0 to Items[_ItemID].BarterCount-1 do
    with Items[_ItemID].Barter^[i] do
    begin
      if Input>0 then
      begin
        Amount:=_Amount;
        CurAmount:=_CurAmount;
        if CurAmount mod Input<>0 then
        begin
          Amount:=Amount*Input;
          CurAmount:=CurAmount*Input;
        end;
        CurAmount:=Output*(CurAmount div Input);
        ItemRatio:=CurAmount/Amount;
        if Item in UsedItems then
        begin
           if ItemRatios[Item]<ItemRatio then
           begin
             SaveRoute:
             if MaxRouteItemWidth<RouteLen+1 then
               MaxRouteItemWidth:=RouteLen+1;
             Routes[RoutesCount].RouteLen :=RouteLen+1;
             Routes[RoutesCount].LoopIndex:=-1;
             for j:=0 to RouteLen-1 do
               with Route[j],Routes[RoutesCount].Route[j] do
               begin
                 if Item=Items[_ItemID].Barter^[i].Item then
                   Routes[RoutesCount].LoopIndex:=j;
                 LocationID:=Location;
                 ShopID    :=Shop;
                 ItemID    :=Item;
                 Count     :=round(ItemRatios[Item]*Amount);
               end;
             Routes[RoutesCount].Route[RouteLen].LocationID:=Location;
             Routes[RoutesCount].Route[RouteLen].ShopID    :=Shop;
             Routes[RoutesCount].Route[RouteLen].ItemID    :=Item;
             Routes[RoutesCount].Route[RouteLen].Count     :=round(ItemRatio*Amount);
             inc(RoutesCount);
           end;
        end
        else if Item=ITEM_ECHO then
        begin
          for j:=0 to RouteLen-1 do
            with Items[Route[j].Item] do
              for k:=0 to BarterCount-1 do
                with Barter[k] do
                  if (Item=ITEM_ECHO)and(ItemRatio/ItemRatios[Route[j].Item]<Output) then
                    goto continue;
          goto SaveRoute
        end
        else
        begin
          ItemRatios[Item]:=ItemRatio;
          Route[RouteLen].Location:=Location;
          Route[RouteLen].Shop:=Shop;
          FindRoutes(Item,Amount,CurAmount);
        end;
      end;
      continue:
    end;
  dec(RouteLen);
  exclude(UsedItems,_ItemID);
end;

function clamp(val,min,max: integer): integer;
asm
  cmp   ecx,eax
  cmovl eax,ecx
  cmp   eax,edx
  cmovl eax,edx
end;

function ListBoxProc(wnd,msg,wParam,lParam: dword): dword;stdcall;
begin
  result:=0;
  if msg<>WM_ERASEBKGND then
    result:=CallWindowProcW(defListBoxProc,wnd,msg,wParam,lParam);
end;

function DlgProc(wnd,msg,wParam,lParam: dword):dword;stdcall;
var
  i,x,y:   integer;
  Buf:     array[0..2047] of WideChar;
  tmpRect: TRECT;
begin
  result:=0;
  case msg of
     WM_DRAWITEM:with PDRAWITEMSTRUCT(lParam)^ do
                 begin
                   tmpRect.Left  :=0;
                   tmpRect.Top   :=0;
                   tmpRect.Right :=rcItem.Right-rcItem.Left;
                   tmpRect.Bottom:=rcItem.Bottom-rcItem.Top;
                   if itemState and ODS_SELECTED>0 then
                   begin
                     FillRect(BackBuf,tmpRect,HighlightBrush);
                     SetTextColor(BackBuf,GetSysColor(COLOR_HIGHLIGHTTEXT));
                   end
                   else
                   begin
                     FillRect(BackBuf,tmpRect,BackBrush);
                     SetTextColor(BackBuf,GetSysColor(COLOR_WINDOWTEXT));
                   end;
                   if wParam=0 then
                   begin
                     BitBlt(BackBuf,0,2,40,52,IconsDC,0,itemID*52,SRCCOPY);
                     SelectObject(BackBuf,hFont);
                     tmpRect.Left:=42;
                     DrawTextW(BackBuf,ItemNames[itemID],-1,tmpRect,DT_WORDBREAK);
                   end
                   else
                     with Routes[itemID] do
                     begin
                       if LoopIndex>-1 then
                         Rectangle(BackBuf,LoopIndex*60-2,2,RouteLen*60-18,tmpRect.Bottom-2);
                       SelectObject(BackBuf,hFontSmall);
                       for i:=0 to RouteLen-1 do
                         with Route[i] do
                         begin
                           if i>0 then
                           begin
                             SetTextColor(BackBuf,200);
                             TextOutW(BackBuf,TmpRect.Left-16,24,'>',1);
                           end;
                           BitBlt(BackBuf,tmpRect.Left,2,40,52,IconsDC,0,itemID*52,SRCCOPY);
                           SetTextColor(BackBuf,$FFFFFF);
                           TextOutW(BackBuf,tmpRect.Left+2,37,@Buf,wsprintfW(@Buf,'%i',Count));
                           SetTextColor(BackBuf,0);
                           inc(tmpRect.Left,60);
                         end;
                     end;
                   BitBlt(hDC,rcItem.Left,rcItem.Top,tmpRect.Right,56,BackBuf,0,0,SRCCOPY);
                   if itemID=SendDlgItemMessageW(wnd,CtlId,LB_GETCOUNT,0,0)-1 then
                   begin
                     GetClientRect(GetDlgItem(wnd,CtlId),tmpRect);
                     tmpRect.Left :=rcItem.Left;
                     tmpRect.Top  :=rcItem.Bottom;
                     tmpRect.Right:=rcItem.Right;
                     FillRect(hDC,tmpRect,BackBrush);
                   end;
                   result:=1;
                 end;
  WM_MEASUREITEM:with PMEASUREITEMSTRUCT(lParam)^ do
                 begin
                   if wParam=0 then
                     itemWidth:=HDelim-4
                   else
                     itemWidth:=RouteListWidth;
                   itemHeight:=56;
                   result:=1;
                 end;
      WM_COMMAND:if hiword(wParam)=BN_CLICKED then
                 begin
                   SendMessageW(lParam,BM_SETCHECK,BST_CHECKED,0);
                   if wParam=BN_CLICKED shr 16+3 then
                   begin
                     font.lfCharSet:=OEM_CHARSET;
                     pointer(ItemNames):=@ItemNameEng;
                     pointer(LocationNames):=@LocationNameEng;
                     pointer(ShopNames):=@ShopNameEng;
                   end
                   else if wParam=BN_CLICKED shr 16+4 then
                   begin
                     font.lfCharSet:=RUSSIAN_CHARSET;
                     pointer(ItemNames):=@ItemNameRus;
                     pointer(LocationNames):=@LocationNameRus;
                     pointer(ShopNames):=@ShopNameRus;
                   end;
                   DeleteObject(hFont);
                   hFont:=CreateFontIndirectW(font);
                   SendMessageW(RouteDetail,WM_SETFONT,hFont,0);
                   DlgProc(wnd,WM_COMMAND,LBN_SELCHANGE shl 16+1,RouteList);
                   InvalidateRect(wnd,0,false);
                 end
                 else if wParam=LBN_SELCHANGE shl 16 then
                 begin
                   i:=SendMessageW(lParam,LB_GETCURSEL,0,0);
                   if i>=0 then
                   begin
                     RoutesCount      :=0;
                     RouteLen         :=0;
                     MaxRouteItemWidth:=0;
                     UsedItems        :=[];
                     ItemRatios[i]    :=1;
                     Route[0].Location:=LOC_START;
                     Route[0].Shop:=SHOP_INVENTORY;
                     FindRoutes(i,1,1);
                     MaxRouteItemWidth:=MaxRouteItemWidth*60-20;
                     SendMessageW(RouteList,LB_SETCOUNT,RoutesCount,0);
                     SendMessageW(RouteList,LB_SETCURSEL,0,0);
                     DlgProc(wnd,WM_COMMAND,LBN_SELCHANGE shl 16+1,RouteList);
                     DlgProc(wnd,WM_SIZE,0,0);
                   end;
                 end
                 else if wParam=LBN_SELCHANGE shl 16+1 then
                 begin
                   x:=SendMessageW(lParam,LB_GETCURSEL,0,0);
                   y:=0;
                   if x>-1 then
                   with Routes[x] do
                   begin
                     for i:=0 to RouteLen-1 do
                       with Route[i] do
                         inc(y,wsprintfW(@Buf[y],'%i. %s %s %ix%s'#13#10,i,LocationNames[LocationID],ShopNames[ShopID],Count,ItemNames[ItemID]));
                     if LoopIndex>-1 then
                       inc(y,wsprintfW(@Buf[y],'%i. goto %i',RouteLen,LoopIndex+1));
                   end;
                   Buf[y]:=#0;
                   SendMessageW(RouteDetail,WM_SETTEXT,0,LongInt(@Buf));
                 end;
  WM_LBUTTONDOWN:if word(loword(lParam)-HDelim)<4 then
                 begin
                   MouseStatus:=1;
                   SetCapture(wnd);
                 end
                 else if word(hiword(lParam)-VDelim)<4 then
                 begin
                   MouseStatus:=2;
                   SetCapture(wnd);
                 end;
    WM_LBUTTONUP:begin
                 ReleaseCapture;
                 MouseStatus:=0;
                 end;
    WM_MOUSEMOVE:begin
                 x:=smallint(lParam);
                 y:=smallint(hiword(lParam));
                 if (word(x-HDelim)<4)or(MouseStatus=1) then
                 begin
                   SetCursor(SizeWE);
                   if wParam and MK_LBUTTON>0 then
                   begin
                     HDelim:=x-2;
                     DlgProc(wnd,WM_SIZE,0,0);
                   end;
                 end
                 else if (word(y-VDelim)<4)or(MouseStatus=2) then
                 begin
                   SetCursor(SizeNS);
                   if wParam and MK_LBUTTON>0 then
                   begin
                     VDelim:=y-2;
                     DlgProc(wnd,WM_SIZE,0,0);
                   end;
                 end;
                 end;
         WM_SIZE:begin
                 GetClientRect(wnd,tmpRect);
                 HDelim:=clamp(HDelim,200,tmpRect.Right-200);
                 VDelim:=clamp(VDelim,100,tmpRect.Bottom-100);
                 MoveWindow(ItemList,2,2,HDelim-2,tmpRect.Bottom-4,false);
                 i:=tmpRect.Right-HDelim-6;
                 MoveWindow(RouteList,HDelim+6,35,i,VDelim-35,false);
                 MoveWindow(RouteDetail,HDelim+6,VDelim+4,i,tmpRect.Bottom-VDelim-6,false);
                 MoveWindow(RadioRus,tmpRect.Right-78,10,75,16,false);
                 MoveWindow(RadioEng,tmpRect.Right-148,10,70,16,false);
                 GetClientRect(RouteList,tmpRect);
                 RouteListWidth:=MaxRouteItemWidth;
                 if MaxRouteItemWidth<tmpRect.Right then
                   RouteListWidth:=tmpRect.Right;
                 SendMessageW(RouteList,LB_SETHORIZONTALEXTENT,RouteListWidth,0);
                 InvalidateRect(wnd,0,false);
                 end;
   WM_INITDIALOG:begin
                 tmpRect.Left  :=0;
                 tmpRect.Top   :=0;
                 tmpRect.Right :=bmi.bmiHeader.biWidth;
                 tmpRect.Bottom:=bmi.bmiHeader.biHeight;
                 FillRect(BackBuf,tmpRect,BackBrush);
                 ItemList   :=GetDlgItem(wnd,0);
                 RouteList  :=GetDlgItem(wnd,1);
                 RouteDetail:=GetDlgItem(wnd,2);
                 RadioEng   :=GetDlgItem(wnd,3);
                 RadioRus   :=GetDlgItem(wnd,4);
                 SetClassLongW(wnd,GCL_HICON,LoadIconW($400000,PWideChar(1)));
                 SendMessageW(ItemList,LB_SETCOUNT,length(Items),0);
                 SendMessageW(ItemList,LB_SETCURSEL,0,0);
                 DlgProc(wnd,WM_SIZE,0,0);
                 if GetUserDefaultUILanguage and $3FF=$19 then  //RU
                   DlgProc(wnd,WM_COMMAND,BN_CLICKED shr 16+4,RadioRus)
                 else
                   DlgProc(wnd,WM_COMMAND,BN_CLICKED shr 16+3,RadioEng);
                 DlgProc(wnd,WM_COMMAND,LBN_SELCHANGE shl 16,ItemList);
                 defListBoxProc:=pointer(SetWindowLongW(ItemList,GWL_WNDPROC,LongInt(@ListBoxProc)));
                 SetWindowLongW(RouteList,GWL_WNDPROC,LongInt(@ListBoxProc));
                 result:=1;
                 end;
        WM_CLOSE:ExitProcess(0);
  end;
end;

begin
  IconsDC:=CreateCompatibleDC(0);
  SelectObject(IconsDC,LoadBitmapW($400000,PWideChar(1)));
  SizeWE:=LoadCursor(0,IDC_SIZEWE);
  SizeNS:=LoadCursor(0,IDC_SIZENS);
  HighlightBrush:=CreateSolidBrush(GetSysColor(COLOR_HIGHLIGHT));
  BackBrush:=CreateSolidBrush(GetSysColor(COLOR_WINDOW));
  hFontSmall:=CreateFontIndirectW(font);
  font.lfHeight:=24;
  font.lfWidth :=8;
  font.lfWeight:=500;

  BackBuf:=CreateCompatibleDC(0);
  bmi.bmiHeader.biWidth    :=GetSystemMetrics(SM_CXSCREEN);
  bmi.bmiHeader.biSizeImage:=bmi.bmiHeader.biWidth*56;
  SelectObject(BackBuf,CreateDIBSection(BackBuf,bmi,DIB_RGB_COLORS,defListBoxProc,0,0));
  SetBkMode(BackBuf,TRANSPARENT);
  DeleteObject(SelectObject(BackBuf,CreatePen(PS_SOLID,5,$FF00)));
  DeleteObject(SelectObject(BackBuf,CreateSolidBrush($FF00)));

  DialogBoxParamW($400000,PWideChar(1),0,@DlgProc,0);
end.
