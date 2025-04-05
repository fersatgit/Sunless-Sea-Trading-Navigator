type
  BarterNode=packed record
             Shop:     byte;
             Location: byte;
             Item:     word;
             input:    word;
             output:   word;
             end;

  TBarter=array[0..0] of BarterNode;
  PBarter=^TBarter;

  TItem=packed record
        BarterCount: Cardinal;
        Barter:      PBarter;
        end;
  PItem=^TItem;

const
  LOC_ADAMSWAY       =0;
  LOC_AIGUL          =1;
  LOC_ANTHE          =2;
  LOC_CUMAENCANAL    =3;
  LOC_DAHUT          =4;
  LOC_EMPIREOFHANDS  =5;
  LOC_FALLENLONDON   =6;
  LOC_GAIDERSMOURN   =7;
  LOC_GANTPOLE       =8;
  LOC_HIDEAWAY       =9;
  LOC_IREM           =10;
  LOC_IRONREPUBLIC   =11;
  LOC_ISLEOFCATS     =12;
  LOC_KHANSHEART     =13;
  LOC_KHANSSHADOW    =14;
  LOC_LOWBARNET      =15;
  LOC_MOUNTPALMERSTON=16;
  LOC_NOOK           =17;
  LOC_POLYTHREME     =18;
  LOC_PORTCARNELIAN  =19;
  LOC_PROSPERINGWRACK=20;
  LOC_ROSEGATE       =21;
  LOC_SAVIORSROCK    =22;
  LOC_SCRIMSHANDER   =23;
  LOC_STATIONIII     =24;
  LOC_STRUGGLINGWRACK=25;
  LOC_THECHELONATE   =26;
  LOC_VARCHAS        =27;
  LOC_VENDERBIGHT    =28;
  LOC_WHITHER        =29;
  LOC_START          =30;

  SHOP_PELEGHASTS_POST                              =0;
  SHOP_REQUISITIONS                                 =1;
  SHOP_STONEMARKET                                  =2;
  SHOP_DAHUT_EXCHANGE                               =3;
  SHOP_MRS_PLENTYS_SHIPSIDE_PROVISIONERS            =4;
  SHOP_WOLFSTACK_EXCHANGE                           =5;
  SHOP_CARROWS_NAVAL_SURPLUS                        =6;
  SHOP_CAMINUS_YARDS                                =7;
  SHOP_THE_IRON_AND_MISERY_COMPANY                  =8;
  SHOP_BULTITUDES_HOUSE_OF_VISION                   =9;
  SHOP_THE_ALARMING_SCHOLAR                         =10;
  SHOP_THE_BRASS_EMBASSY                            =11;
  SHOP_THE_ARRANT_LIMPET                            =12;
  SHOP_THE_FRIENDLY_FACE                            =13;
  SHOP_JONAHS_END                                   =14;
  SHOP_PORTENTUM                                    =15;
  SHOP_EXILE_BAZAAR                                 =16;
  SHOP_THE_FISHER_OF_DAWN                           =17;
  SHOP_THRESHOLD                                    =18;
  SHOP_WIND_COME_CALLING                            =19;
  SHOP_MARKET_OF_HUNGERS_FIRE_IN_THE_BELLY          =20;
  SHOP_THE_CALVARY_DOCTRINE_THE_HOUSE_OF_MILKS      =21;
  SHOP_THE_GESUNDHEIT_CONSPIRACY_HOUSE_OF_HARVESTS  =22;
  SHOP_THE_PARLIAMENT_OF_FLIES_HOUSE_OF_PLEASURES   =23;
  SHOP_EXPULSUS_HOUSE_OF_HARMS                      =24;
  SHOP_LICENSED_EXCHANGE                            =25;
  SHOP_RED_STALLION_PUBLISHING                      =26;
  SHOP_DEARLY_DEPARTED                              =27;
  SHOP_TRAVELLERS_FRIEND                            =28;
  SHOP_LOW_CHURCH                                   =29;
  SHOP_MALEBOLGE_EXCAVATIONS                        =30;
  SHOP_DAILY_BREAD                                  =31;
  SHOP_THE_YAWNING_MAW                              =32;
  SHOP_TEMPLE_OF_LABOURS                            =33;
  SHOP_DOCKSIDE_MARKET                              =34;
  SHOP_SAPPHIRE_EXCHANGE                            =35;
  SHOP_PROVING_GROUND                               =36;
  SHOP_REMAINDER                                    =37;
  SHOP_UNCLE_ANKLES_LEAN_PLACE                      =38;
  SHOP_ARCADE_OF_SIGHS                              =39;
  SHOP_HOLLOW_TEMPLE                                =40;
  SHOP_THE_CHARNEL_LOUNGE                           =41;
  SHOP_FORTUNE_AND_FORTUNE                          =42;
  SHOP_THE_HUNTERS_CAGE                             =43;
  SHOP_HULL_HARVEST                                 =44;
  SHOP_HARBOUR_PROVISIONERS                         =45;
  SHOP_INTERACTION                                  =46;
  SHOP_INTERACTION_DAILY                            =47;
  SHOP_THE_LABYRINTH_OF_TIGERS                      =48;
  SHOP_SURFACE                                      =49;
  SHOP_INVENTORY                                    =50;

  ITEM_A_CASKET_OF_SAPPHIRES                            =0;
  ITEM_A_FIRKIN_OF_RED_HONEY                            =1;
  ITEM_A_MIRRORCATCH_BOX_FULL_OF_VERY_ANGRY_DREAM_SNAKES=2;
  ITEM_A_POT_OF_VIOLANT_INK                             =3;
  ITEM_AMBIGUOUS_EOLITH                                 =4;
  ITEM_APPROVED_ROMANTIC_LITERATURE                     =5;
  ITEM_BALE_OF_PARABOLA_LINEN                           =6;
  ITEM_BOLTS_OF_SPIDER_SILK                             =7;
  ITEM_CAPTIVATING_TREASURE                             =8;
  ITEM_CARBOY_OF_PRIMORDIAL_SHRIEKS                     =9;
  ITEM_CASK_OF_MUSHROOM_WINE                            =10;
  ITEM_COLOSSAL_FLUKE_CORE                              =11;
  ITEM_CRATE_OF_HUMAN_SOULS                             =12;
  ITEM_DEVILBONE_DICE                                   =13;
  ITEM_DREAD_SURMISE                                    =14;
  ITEM_DROWNING_PEARL                                   =15;
  ITEM_ECHO                                             =16;
  ITEM_EMPTY_MIRRORCATCH_BOX                            =17;
  ITEM_EXTRAORDINARY_IMPLICATION                        =18;
  ITEM_FIRKIN_OF_PRISONERS_HONEY                        =19;
  ITEM_FLARE                                            =20;
  ITEM_FOXFIRE_CANDLES                                  =21;
  ITEM_FUEL                                             =22;
  ITEM_HARLOT_FRY                                       =23;
  ITEM_HUNTERS_EYE                                      =24;
  ITEM_HUNTING_TROPHY                                   =25;
  ITEM_JUDGEMENTS_EGG                                   =26;
  ITEM_LAMENTABLE_RELIC                                 =27;
  ITEM_LIVE_SPECIMEN                                    =28;
  ITEM_MEMORY_OF_DISTANT_SHORES                         =29;
  ITEM_MOUNTAIN_SHERD                                   =30;
  ITEM_MT_NOMADS_HEART                                  =31;
  ITEM_MUTERSALT                                        =32;
  ITEM_OUTLANDISH_ARTEFACT                              =33;
  ITEM_ROMANTIC_LITERATURE                              =34;
  ITEM_ROYAL_BLUE_FEATHER                               =35;
  ITEM_SACK_OF_DARKDROP_COFFEE_BEANS                    =36;
  ITEM_SCINTILLACK                                      =37;
  ITEM_SEARING_ENIGMA                                   =38;
  ITEM_SECRET                                           =39;
  ITEM_SOLACEFRUIT                                      =40;
  ITEM_SOOTHE_AND_COOPER_LONG_BOX                       =41;
  ITEM_STAION_III_HEARTHMETAL_IGNOT                     =42;
  ITEM_STAR_SHELL                                       =43;
  ITEM_STRANGE_CATCH                                    =44;
  ITEM_STYGIAN_IVORY                                    =45;
  ITEM_SUNLIGHT_FILLED_MIRRORCATCH_BOX                  =46;
  ITEM_SUPPLIES                                         =47;
  ITEM_TALE_OF_TERROR                                   =48;
  ITEM_THE_FIGUREHEAD_OF_THE_EATER_OF_NAMES             =49;
  ITEM_THE_HEART_OF_THE_TREE_OF_AGES                    =50;
  ITEM_TOMB_COLONIST                                    =51;
  ITEM_TORPEDO_COMPONENTS                               =52;
  ITEM_UNREAD_LOG                                       =53;
  ITEM_UNSTAMPED_CRATE_OF_BRILLIANT_SOULS               =54;
  ITEM_UNSTAMPED_CRATE_OF_HUMAN_SOULS                   =55;
  ITEM_UTTERSHROOM_SPOROULE                             =56;
  ITEM_VISION_OF_THE_SURFACE                            =57;
  ITEM_WAKEFUL_IDOL                                     =58;
  ITEM_WATCHFUL_CURIO                                   =59;
  ITEM_ZEE_ZTORY                                        =60;
  ITEM_ZZOUP                                            =61;

  BARTER_A_CASKET_OF_SAPPHIRES                            :array[0..11] of word=(LOC_HIDEAWAY        shr 8+SHOP_EXILE_BAZAAR                               ,ITEM_MUTERSALT                     ,1,2,
                                                                                 LOC_DAHUT           shl 8+SHOP_DAHUT_EXCHANGE                             ,ITEM_CAPTIVATING_TREASURE          ,11,1,
                                                                                 LOC_THECHELONATE    shl 8+SHOP_UNCLE_ANKLES_LEAN_PLACE                    ,ITEM_ECHO                          ,1,99);
  BARTER_A_FIRKIN_OF_RED_HONEY                            :array[0..7]  of word=(LOC_EMPIREOFHANDS   shl 8+SHOP_INTERACTION                                ,ITEM_A_POT_OF_VIOLANT_INK          ,1,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_BRASS_EMBASSY                          ,ITEM_ECHO                          ,1,999);
  BARTER_A_MIRRORCATCH_BOX_FULL_OF_VERY_ANGRY_DREAM_SNAKES:array[0..3]  of word=(LOC_KHANSSHADOW     shl 8+SHOP_TRAVELLERS_FRIEND                          ,ITEM_ECHO                          ,1,500);
  BARTER_A_POT_OF_VIOLANT_INK                             :array[0..3]  of word=(LOC_SCRIMSHANDER    shl 8+SHOP_REMAINDER                                  ,ITEM_ECHO                          ,1,250);
  BARTER_AMBIGUOUS_EOLITH                                 :array[0..3]  of word=(LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,70);
  BARTER_APPROVED_ROMANTIC_LITERATURE                     :array[0..3]  of word=(LOC_FALLENLONDON    shl 8+SHOP_WOLFSTACK_EXCHANGE                         ,ITEM_ECHO                          ,1,22);
  BARTER_BALE_OF_PARABOLA_LINEN                           :array[0..3]  of word=(LOC_DAHUT           shl 8+SHOP_DAHUT_EXCHANGE                             ,ITEM_ECHO                          ,1,66);
  BARTER_BOLTS_OF_SPIDER_SILK                             :array[0..3]  of word=(LOC_PROSPERINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_ECHO                          ,1,56);
  BARTER_CAPTIVATING_TREASURE                             :array[0..11] of word=(LOC_IREM            shl 8+SHOP_THRESHOLD                                  ,ITEM_FUEL                          ,1,50,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_THE_GESUNDHEIT_CONSPIRACY_HOUSE_OF_HARVESTS,ITEM_SOOTHE_AND_COOPER_LONG_BOX    ,1,1,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_TRAVELLERS_FRIEND                          ,ITEM_ECHO                          ,1,1000);
  BARTER_CARBOY_OF_PRIMORDIAL_SHRIEKS                     :array[0..7]  of word=(LOC_SCRIMSHANDER    shl 8+SHOP_REMAINDER                                  ,ITEM_MUTERSALT                     ,1,1,
                                                                                 LOC_THECHELONATE    shl 8+SHOP_UNCLE_ANKLES_LEAN_PLACE                    ,ITEM_ECHO                          ,1,37);
  BARTER_CASK_OF_MUSHROOM_WINE                            :array[0..11] of word=(LOC_EMPIREOFHANDS   shl 8+SHOP_INTERACTION                                ,ITEM_SACK_OF_DARKDROP_COFFEE_BEANS ,1,1,
                                                                                 LOC_ANTHE           shl 8+SHOP_INTERACTION                                ,ITEM_SUPPLIES                      ,1,1,
                                                                                 LOC_ADAMSWAY        shl 8+SHOP_PELEGHASTS_POST                            ,ITEM_ECHO                          ,1,24);
  BARTER_COLOSSAL_FLUKE_CORE                              :array[0..7]  of word=(LOC_IRONREPUBLIC    shl 8+SHOP_THE_PARLIAMENT_OF_FLIES_HOUSE_OF_PLEASURES ,ITEM_JUDGEMENTS_EGG                ,1,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,500);
  BARTER_CRATE_OF_HUMAN_SOULS                             :array[0..3]  of word=(LOC_FALLENLONDON    shl 8+SHOP_THE_BRASS_EMBASSY                          ,ITEM_ECHO                          ,1,63);
  BARTER_DEVILBONE_DICE                                   :array[0..7]  of word=(LOC_IRONREPUBLIC    shl 8+SHOP_EXPULSUS_HOUSE_OF_HARMS                    ,ITEM_LAMENTABLE_RELIC              ,1,5,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_DEARLY_DEPARTED                            ,ITEM_ECHO                          ,1,22);
  BARTER_DREAD_SURMISE                                    :array[0..3]  of word=(LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_SEARING_ENIGMA                ,1,10);
  BARTER_DROWNING_PEARL                                   :array[0..3]  of word=(LOC_GAIDERSMOURN    shl 8+SHOP_INTERACTION_DAILY                          ,ITEM_SOLACEFRUIT                   ,1,2);
  BARTER_ECHO                                             :array[0..107]of word=(LOC_FALLENLONDON    shl 8+SHOP_WOLFSTACK_EXCHANGE                         ,ITEM_FIRKIN_OF_PRISONERS_HONEY     ,25,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_WOLFSTACK_EXCHANGE                         ,ITEM_CASK_OF_MUSHROOM_WINE         ,21,1,
                                                                                 LOC_PORTCARNELIAN   shl 8+SHOP_SAPPHIRE_EXCHANGE                          ,ITEM_MOUNTAIN_SHERD                ,2000,1,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_TRAVELLERS_FRIEND                          ,ITEM_OUTLANDISH_ARTEFACT           ,150,1,
                                                                                 LOC_MOUNTPALMERSTON shl 8+SHOP_MALEBOLGE_EXCAVATIONS                      ,ITEM_DEVILBONE_DICE                ,19,1,
                                                                                 LOC_DAHUT           shl 8+SHOP_DAHUT_EXCHANGE                             ,ITEM_DROWNING_PEARL                ,30,1,
                                                                                 LOC_MOUNTPALMERSTON shl 8+SHOP_MALEBOLGE_EXCAVATIONS                      ,ITEM_ZZOUP                         ,70,1,
                                                                                 LOC_KHANSHEART      shl 8+SHOP_RED_STALLION_PUBLISHING                    ,ITEM_ROMANTIC_LITERATURE           ,19,1,
                                                                                 LOC_ADAMSWAY        shl 8+SHOP_PELEGHASTS_POST                            ,ITEM_SACK_OF_DARKDROP_COFFEE_BEANS ,38,1,
                                                                                 LOC_ANTHE           shl 8+SHOP_STONEMARKET                                ,ITEM_AMBIGUOUS_EOLITH              ,30,1,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_TRAVELLERS_FRIEND                          ,ITEM_CAPTIVATING_TREASURE          ,1500,1,
                                                                                 LOC_SCRIMSHANDER    shl 8+SHOP_REMAINDER                                  ,ITEM_LAMENTABLE_RELIC              ,10,1,
                                                                                 LOC_IREM            shl 8+SHOP_THRESHOLD                                  ,ITEM_STRANGE_CATCH                 ,25,1,
                                                                                 LOC_CUMAENCANAL     shl 8+SHOP_SURFACE                                    ,ITEM_SUPPLIES                      ,5,1,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_TRAVELLERS_FRIEND                          ,ITEM_EMPTY_MIRRORCATCH_BOX         ,250,1,
                                                                                 LOC_SAVIORSROCK     shl 8+SHOP_INTERACTION                                ,ITEM_BOLTS_OF_SPIDER_SILK          ,40,1,
                                                                                 LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_SECRET                        ,999,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_MRS_PLENTYS_SHIPSIDE_PROVISIONERS          ,ITEM_FLARE                         ,10,1,
                                                                                 LOC_NOOK            shl 8+SHOP_THE_YAWNING_MAW                            ,ITEM_STYGIAN_IVORY                 ,26,1,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_MARKET_OF_HUNGERS_FIRE_IN_THE_BELLY        ,ITEM_FUEL                          ,8,1,
                                                                                 LOC_PROSPERINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_TORPEDO_COMPONENTS            ,4,1,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_THE_PARLIAMENT_OF_FLIES_HOUSE_OF_PLEASURES ,ITEM_BALE_OF_PARABOLA_LINEN        ,57,1,
                                                                                 LOC_GAIDERSMOURN    shl 8+SHOP_THE_ARRANT_LIMPET                          ,ITEM_SOLACEFRUIT                   ,250,1,
                                                                                 LOC_ADAMSWAY        shl 8+SHOP_PELEGHASTS_POST                            ,ITEM_FOXFIRE_CANDLES               ,30,1,
                                                                                 LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_EXTRAORDINARY_IMPLICATION     ,333,1,
                                                                                 LOC_PORTCARNELIAN   shl 8+SHOP_SAPPHIRE_EXCHANGE                          ,ITEM_A_CASKET_OF_SAPPHIRES         ,86,1,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_DEARLY_DEPARTED                            ,ITEM_CRATE_OF_HUMAN_SOULS          ,57,1);
  BARTER_EMPTY_MIRRORCATCH_BOX                            :array[0..3]  of word=(LOC_KHANSSHADOW     shl 8+SHOP_TRAVELLERS_FRIEND                          ,ITEM_ECHO                          ,1,200);
  BARTER_EXTRAORDINARY_IMPLICATION                        :array[0..7]  of word=(LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_SEARING_ENIGMA                ,5,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,250);
  BARTER_FIRKIN_OF_PRISONERS_HONEY                        :array[0..11] of word=(LOC_EMPIREOFHANDS   shl 8+SHOP_INTERACTION                                ,ITEM_ROMANTIC_LITERATURE           ,1,2,
                                                                                 LOC_GANTPOLE        shl 8+SHOP_JONAHS_END                                 ,ITEM_CARBOY_OF_PRIMORDIAL_SHRIEKS  ,1,1,
                                                                                 LOC_PROSPERINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_ECHO                          ,1,28);
  BARTER_FLARE                                            :array[0..3]  of word=(0,0,0,0);
  BARTER_FOXFIRE_CANDLES                                  :array[0..7]  of word=(LOC_STRUGGLINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_DEVILBONE_DICE                ,1,2,
                                                                                 LOC_HIDEAWAY        shl 8+SHOP_EXILE_BAZAAR                               ,ITEM_ECHO                          ,1,35);
  BARTER_FUEL                                             :array[0..3]  of word=(LOC_STRUGGLINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_ECHO                          ,1,11);
  BARTER_HARLOT_FRY                                       :array[0..7]  of word=(LOC_GANTPOLE        shl 8+SHOP_PORTENTUM                                  ,ITEM_HUNTING_TROPHY                ,1,10,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_LABYRINTH_OF_TIGERS                    ,ITEM_ECHO                          ,1,500);
  BARTER_HUNTERS_EYE                                      :array[0..3]  of word=(LOC_ROSEGATE        shl 8+SHOP_PROVING_GROUND                             ,ITEM_ECHO                          ,1,100);
  BARTER_HUNTING_TROPHY                                   :array[0..3]  of word=(LOC_SCRIMSHANDER    shl 8+SHOP_REMAINDER                                  ,ITEM_ECHO                          ,1,65);
  BARTER_JUDGEMENTS_EGG                                   :array[0..3]  of word=(LOC_POLYTHREME      shl 8+SHOP_TEMPLE_OF_LABOURS                          ,ITEM_ECHO                          ,1,600);
  BARTER_LAMENTABLE_RELICS                                :array[0..11] of word=(LOC_IRONREPUBLIC    shl 8+SHOP_EXPULSUS_HOUSE_OF_HARMS                    ,ITEM_FUEL                          ,1,1,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_EXPULSUS_HOUSE_OF_HARMS                    ,ITEM_CRATE_OF_HUMAN_SOULS          ,11,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,5);
  BARTER_LIVE_SPECIMEN                                    :array[0..7]  of word=(LOC_GANTPOLE        shl 8+SHOP_PORTENTUM                                  ,ITEM_STRANGE_CATCH                 ,1,7,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,100);
  BARTER_MEMORY_OF_DISTANT_SHORES                         :array[0..11] of word=(LOC_LOWBARNET       shl 8+SHOP_LOW_CHURCH                                 ,ITEM_SUPPLIES                      ,3,1,
                                                                                 LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_TALE_OF_TERROR                ,2,1,
                                                                                 LOC_VENDERBIGHT     shl 8+SHOP_HOLLOW_TEMPLE                              ,ITEM_ECHO                          ,1,12);
  BARTER_MOUNTAIN_SHERD                                   :array[0..3]  of word=(LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_BALE_OF_PARABOLA_LINEN        ,1,20);
  BARTER_MT_NOMADS_HEART                                  :array[0..3]  of word=(LOC_THECHELONATE    shl 8+SHOP_UNCLE_ANKLES_LEAN_PLACE                    ,ITEM_SEARING_ENIGMA                ,1,1);
  BARTER_MUTERSALT                                        :array[0..11] of word=(LOC_ANTHE           shl 8+SHOP_STONEMARKET                                ,ITEM_SCINTILLACK                   ,1,1,
                                                                                 LOC_AIGUL           shl 8+SHOP_REQUISITIONS                               ,ITEM_FOXFIRE_CANDLES               ,1,2,
                                                                                 LOC_KHANSHEART      shl 8+SHOP_LICENSED_EXCHANGE                          ,ITEM_ECHO                          ,1,56);
  BARTER_OUTLANDISH_ARTEFACT                              :array[0..3]  of word=(LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,100);
  BARTER_ROMANTIC_LITERATURE                              :array[0..7]  of word=(LOC_ANTHE           shl 8+SHOP_INTERACTION                                ,ITEM_SUPPLIES                      ,1,1,
                                                                                 LOC_PORTCARNELIAN   shl 8+SHOP_SAPPHIRE_EXCHANGE                          ,ITEM_ECHO                          ,1,22);
  BARTER_ROYAL_BLUE_FEATHER                               :array[0..3]  of word=(LOC_KHANSHEART      shl 8+SHOP_LICENSED_EXCHANGE                          ,ITEM_ECHO                          ,1,2);
  BARTER_SACK_OF_DARKDROP_COFFEE_BEANS                    :array[0..7]  of word=(LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_BALE_OF_PARABOLA_LINEN        ,1,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_WOLFSTACK_EXCHANGE                         ,ITEM_ECHO                          ,1,44);
  BARTER_SCINTILLACK                                      :array[0..7]  of word=(LOC_PROSPERINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_A_CASKET_OF_SAPPHIRES         ,1,1,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_THE_PARLIAMENT_OF_FLIES_HOUSE_OF_PLEASURES ,ITEM_ECHO                          ,1,74);
  BARTER_SEARING_ENIGMA                                   :array[0..7]  of word=(LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_EXTRAORDINARY_IMPLICATION     ,1,3,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,1000);
  BARTER_SECRET                                           :array[0..23] of word=(LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_LAMENTABLE_RELIC              ,1,1,
                                                                                 LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_AMBIGUOUS_EOLITH              ,1,1,
                                                                                 LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_WATCHFUL_CURIO                ,1,1,
                                                                                 LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_SOOTHE_AND_COOPER_LONG_BOX    ,3,1,
                                                                                 LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_EMPTY_MIRRORCATCH_BOX         ,3,1,
                                                                                 LOC_IREM            shl 8+SHOP_THE_FISHER_OF_DAWN                         ,ITEM_JUDGEMENTS_EGG                ,10,1);
  BARTER_SOLACEFRUIT                                      :array[0..7]  of word=(LOC_AIGUL           shl 8+SHOP_REQUISITIONS                               ,ITEM_MEMORY_OF_DISTANT_SHORES      ,1,4,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_WOLFSTACK_EXCHANGE                         ,ITEM_ECHO                          ,1,50);
  BARTER_SOOTHE_AND_COOPER_LONG_BOX                       :array[0..7]  of word=(LOC_STATIONIII      shl 8+SHOP_INTERACTION                                ,ITEM_STAION_III_HEARTHMETAL_IGNOT  ,1,1,
                                                                                 LOC_STATIONIII      shl 8+SHOP_INTERACTION                                ,ITEM_ECHO                          ,1,100);
  BARTER_STAION_III_HEARTHMETAL_IGNOT                     :array[0..7]  of word=(LOC_ANTHE           shl 8+SHOP_INTERACTION                                ,ITEM_SUPPLIES                      ,1,5,
                                                                                 LOC_ROSEGATE        shl 8+SHOP_PROVING_GROUND                             ,ITEM_ECHO                          ,1,120);
  BARTER_STAR_SHELL                                       :array[0..7]  of word=(LOC_WHITHER         shl 8+SHOP_THE_HUNTERS_CAGE                           ,ITEM_EXTRAORDINARY_IMPLICATION     ,1,2,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_DEARLY_DEPARTED                            ,ITEM_ECHO                          ,1,500);
  BARTER_STRANGE_CATCH                                    :array[0..7]  of word=(LOC_VENDERBIGHT     shl 8+SHOP_INTERACTION                                ,ITEM_SUPPLIES                      ,1,3,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,10);
  BARTER_STYGIAN_IVORY                                    :array[0..11] of word=(LOC_WHITHER         shl 8+SHOP_THE_HUNTERS_CAGE                           ,ITEM_TALE_OF_TERROR                ,1,3,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_EXPULSUS_HOUSE_OF_HARMS                    ,ITEM_LAMENTABLE_RELIC              ,1,6,
                                                                                 LOC_POLYTHREME      shl 8+SHOP_TEMPLE_OF_LABOURS                          ,ITEM_ECHO                          ,1,30);
  BARTER_SUNLIGHT_FILLED_MIRRORCATCH_BOX                  :array[0..7]  of word=(LOC_NOOK            shl 8+SHOP_THE_YAWNING_MAW                            ,ITEM_A_CASKET_OF_SAPPHIRES         ,1,7,
                                                                                 LOC_ISLEOFCATS      shl 8+SHOP_INTERACTION                                ,ITEM_ECHO                          ,1,400);
  BARTER_SUPPLIES                                         :array[0..19] of word=(LOC_WHITHER         shl 8+SHOP_THE_HUNTERS_CAGE                           ,ITEM_TALE_OF_TERROR                ,1,1,
                                                                                 LOC_STRUGGLINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_FIRKIN_OF_PRISONERS_HONEY     ,1,1,
                                                                                 LOC_STRUGGLINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_SACK_OF_DARKDROP_COFFEE_BEANS ,3,1,
                                                                                 LOC_SAVIORSROCK     shl 8+SHOP_INTERACTION                                ,ITEM_BOLTS_OF_SPIDER_SILK          ,1,1,
                                                                                 LOC_IRONREPUBLIC    shl 8+SHOP_THE_CALVARY_DOCTRINE_THE_HOUSE_OF_MILKS    ,ITEM_ECHO                          ,1,25);
  BARTER_TALE_OF_TERROR                                   :array[0..15] of word=(LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_ZEE_ZTORY                     ,2,1,
                                                                                 LOC_WHITHER         shl 8+SHOP_THE_HUNTERS_CAGE                           ,ITEM_SUPPLIES                      ,2,1,
                                                                                 LOC_LOWBARNET       shl 8+SHOP_LOW_CHURCH                                 ,ITEM_FUEL                          ,2,1,
                                                                                 LOC_GANTPOLE        shl 8+SHOP_PORTENTUM                                  ,ITEM_STYGIAN_IVORY                 ,3,1);
  BARTER_THE_FIGUREHEAD_OF_THE_EATER_OF_NAMES             :array[0..7]  of word=(LOC_WHITHER         shl 8+SHOP_THE_HUNTERS_CAGE                           ,ITEM_EXTRAORDINARY_IMPLICATION     ,1,1,
                                                                                 LOC_KHANSSHADOW     shl 8+SHOP_DEARLY_DEPARTED                            ,ITEM_ECHO                          ,1,250);
  BARTER_THE_HEART_OF_THE_TREE_OF_AGES                    :array[0..3]  of word=(LOC_GANTPOLE        shl 8+SHOP_PORTENTUM                                  ,ITEM_COLOSSAL_FLUKE_CORE           ,1,1);
  BARTER_TOMB_COLONIST                                    :array[0..3]  of word=(LOC_VENDERBIGHT     shl 8+SHOP_THE_CHARNEL_LOUNGE                         ,ITEM_ECHO                          ,1,15);
  BARTER_TORPEDO_COMPONENTS                               :array[0..7]  of word=(LOC_STRUGGLINGWRACK shl 8+SHOP_HULL_HARVEST                               ,ITEM_BALE_OF_PARABOLA_LINEN        ,12,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_CARROWS_NAVAL_SURPLUS                      ,ITEM_ECHO                          ,1,1);
  BARTER_UNREAD_LOG                                       :array[0..3]  of word=(LOC_SCRIMSHANDER    shl 8+SHOP_REMAINDER                                  ,ITEM_ECHO                          ,1,25);
  BARTER_UNSTAMPED_CRATE_OF_BRILLIANT_SOULS               :array[0..3]  of word=(LOC_GAIDERSMOURN    shl 8+SHOP_THE_FRIENDLY_FACE                          ,ITEM_ECHO                          ,1,150);
  BARTER_UNSTAMPED_CRATE_OF_HUMAN_SOULS                   :array[0..3]  of word=(LOC_GAIDERSMOURN    shl 8+SHOP_THE_FRIENDLY_FACE                          ,ITEM_ECHO                          ,1,40);
  BARTER_UTTERSHROOM_SPOROULE                             :array[0..3]  of word=(LOC_ROSEGATE        shl 8+SHOP_PROVING_GROUND                             ,ITEM_ECHO                          ,1,750);
  BARTER_VISION_OF_THE_SURFACE                            :array[0..7]  of word=(LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_MEMORY_OF_DISTANT_SHORES      ,2,1,
                                                                                 LOC_WHITHER         shl 8+SHOP_HOLLOW_TEMPLE                              ,ITEM_ECHO                          ,1,15);
  BARTER_WAKEFUL_IDOL                                     :array[0..3]  of word=(LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,100);
  BARTER_WATCHFUL_CURIO                                   :array[0..7]  of word=(LOC_POLYTHREME      shl 8+SHOP_INTERACTION                                ,ITEM_WAKEFUL_IDOL                  ,1,1,
                                                                                 LOC_FALLENLONDON    shl 8+SHOP_THE_ALARMING_SCHOLAR                       ,ITEM_ECHO                          ,1,20);
  BARTER_ZEE_ZTORY                                        :array[0..11] of word=(LOC_IREM            shl 8+SHOP_WIND_COME_CALLING                          ,ITEM_VISION_OF_THE_SURFACE         ,2,1,
                                                                                 LOC_WHITHER         shl 8+SHOP_FORTUNE_AND_FORTUNE                        ,ITEM_FUEL                          ,1,1,
                                                                                 LOC_WHITHER         shl 8+SHOP_FORTUNE_AND_FORTUNE                        ,ITEM_MUTERSALT                     ,5,1);
  BARTER_ZZOUP                                            :array[0..3]  of word=(LOC_IRONREPUBLIC    shl 8+SHOP_THE_CALVARY_DOCTRINE_THE_HOUSE_OF_MILKS    ,ITEM_ECHO                          ,1,77);

  Items: array[0..61] of TItem=((BarterCount: length(BARTER_A_CASKET_OF_SAPPHIRES) shr 2;                            Barter: @BARTER_A_CASKET_OF_SAPPHIRES),
                                (BarterCount: length(BARTER_A_FIRKIN_OF_RED_HONEY) shr 2;                            Barter: @BARTER_A_FIRKIN_OF_RED_HONEY),
                                (BarterCount: length(BARTER_A_MIRRORCATCH_BOX_FULL_OF_VERY_ANGRY_DREAM_SNAKES) shr 2;Barter: @BARTER_A_MIRRORCATCH_BOX_FULL_OF_VERY_ANGRY_DREAM_SNAKES),
                                (BarterCount: length(BARTER_A_POT_OF_VIOLANT_INK) shr 2;                             Barter: @BARTER_A_POT_OF_VIOLANT_INK),
                                (BarterCount: length(BARTER_AMBIGUOUS_EOLITH) shr 2;                                 Barter: @BARTER_AMBIGUOUS_EOLITH),
                                (BarterCount: length(BARTER_APPROVED_ROMANTIC_LITERATURE) shr 2;                     Barter: @BARTER_APPROVED_ROMANTIC_LITERATURE),
                                (BarterCount: length(BARTER_BALE_OF_PARABOLA_LINEN) shr 2;                           Barter: @BARTER_BALE_OF_PARABOLA_LINEN),
                                (BarterCount: length(BARTER_BOLTS_OF_SPIDER_SILK) shr 2;                             Barter: @BARTER_BOLTS_OF_SPIDER_SILK),
                                (BarterCount: length(BARTER_CAPTIVATING_TREASURE) shr 2;                             Barter: @BARTER_CAPTIVATING_TREASURE),
                                (BarterCount: length(BARTER_CARBOY_OF_PRIMORDIAL_SHRIEKS) shr 2;                     Barter: @BARTER_CARBOY_OF_PRIMORDIAL_SHRIEKS),
                                (BarterCount: length(BARTER_CASK_OF_MUSHROOM_WINE) shr 2;                            Barter: @BARTER_CASK_OF_MUSHROOM_WINE),
                                (BarterCount: length(BARTER_COLOSSAL_FLUKE_CORE) shr 2;                              Barter: @BARTER_COLOSSAL_FLUKE_CORE),
                                (BarterCount: length(BARTER_CRATE_OF_HUMAN_SOULS) shr 2;                             Barter: @BARTER_CRATE_OF_HUMAN_SOULS),
                                (BarterCount: length(BARTER_DEVILBONE_DICE) shr 2;                                   Barter: @BARTER_DEVILBONE_DICE),
                                (BarterCount: length(BARTER_DREAD_SURMISE) shr 2;                                    Barter: @BARTER_DREAD_SURMISE),
                                (BarterCount: length(BARTER_DROWNING_PEARL) shr 2;                                   Barter: @BARTER_DROWNING_PEARL),
                                (BarterCount: length(BARTER_ECHO) shr 2;                                             Barter: @BARTER_ECHO),
                                (BarterCount: length(BARTER_EMPTY_MIRRORCATCH_BOX) shr 2;                            Barter: @BARTER_EMPTY_MIRRORCATCH_BOX),
                                (BarterCount: length(BARTER_EXTRAORDINARY_IMPLICATION) shr 2;                        Barter: @BARTER_EXTRAORDINARY_IMPLICATION),
                                (BarterCount: length(BARTER_FIRKIN_OF_PRISONERS_HONEY) shr 2;                        Barter: @BARTER_FIRKIN_OF_PRISONERS_HONEY),
                                (BarterCount: length(BARTER_FLARE) shr 2;                                            Barter: @BARTER_FLARE),
                                (BarterCount: length(BARTER_FOXFIRE_CANDLES) shr 2;                                  Barter: @BARTER_FOXFIRE_CANDLES),
                                (BarterCount: length(BARTER_FUEL) shr 2;                                             Barter: @BARTER_FUEL),
                                (BarterCount: length(BARTER_HARLOT_FRY) shr 2;                                       Barter: @BARTER_HARLOT_FRY),
                                (BarterCount: length(BARTER_HUNTERS_EYE) shr 2;                                      Barter: @BARTER_HUNTERS_EYE),
                                (BarterCount: length(BARTER_HUNTING_TROPHY) shr 2;                                   Barter: @BARTER_HUNTING_TROPHY),
                                (BarterCount: length(BARTER_JUDGEMENTS_EGG) shr 2;                                   Barter: @BARTER_JUDGEMENTS_EGG),
                                (BarterCount: length(BARTER_LAMENTABLE_RELICS) shr 2;                                Barter: @BARTER_LAMENTABLE_RELICS),
                                (BarterCount: length(BARTER_LIVE_SPECIMEN) shr 2;                                    Barter: @BARTER_LIVE_SPECIMEN),
                                (BarterCount: length(BARTER_MEMORY_OF_DISTANT_SHORES) shr 2;                         Barter: @BARTER_MEMORY_OF_DISTANT_SHORES),
                                (BarterCount: length(BARTER_MOUNTAIN_SHERD) shr 2;                                   Barter: @BARTER_MOUNTAIN_SHERD),
                                (BarterCount: length(BARTER_MT_NOMADS_HEART) shr 2;                                  Barter: @BARTER_MT_NOMADS_HEART),
                                (BarterCount: length(BARTER_MUTERSALT) shr 2;                                        Barter: @BARTER_MUTERSALT),
                                (BarterCount: length(BARTER_OUTLANDISH_ARTEFACT) shr 2;                              Barter: @BARTER_OUTLANDISH_ARTEFACT),
                                (BarterCount: length(BARTER_ROMANTIC_LITERATURE) shr 2;                              Barter: @BARTER_ROMANTIC_LITERATURE),
                                (BarterCount: length(BARTER_ROYAL_BLUE_FEATHER) shr 2;                               Barter: @BARTER_ROYAL_BLUE_FEATHER),
                                (BarterCount: length(BARTER_SACK_OF_DARKDROP_COFFEE_BEANS) shr 2;                    Barter: @BARTER_SACK_OF_DARKDROP_COFFEE_BEANS),
                                (BarterCount: length(BARTER_SCINTILLACK) shr 2;                                      Barter: @BARTER_SCINTILLACK),
                                (BarterCount: length(BARTER_SEARING_ENIGMA) shr 2;                                   Barter: @BARTER_SEARING_ENIGMA),
                                (BarterCount: length(BARTER_SECRET) shr 2;                                           Barter: @BARTER_SECRET),
                                (BarterCount: length(BARTER_SOLACEFRUIT) shr 2;                                      Barter: @BARTER_SOLACEFRUIT),
                                (BarterCount: length(BARTER_SOOTHE_AND_COOPER_LONG_BOX) shr 2;                       Barter: @BARTER_SOOTHE_AND_COOPER_LONG_BOX),
                                (BarterCount: length(BARTER_STAION_III_HEARTHMETAL_IGNOT) shr 2;                     Barter: @BARTER_STAION_III_HEARTHMETAL_IGNOT),
                                (BarterCount: length(BARTER_STAR_SHELL) shr 2;                                       Barter: @BARTER_STAR_SHELL),
                                (BarterCount: length(BARTER_STRANGE_CATCH) shr 2;                                    Barter: @BARTER_STRANGE_CATCH),
                                (BarterCount: length(BARTER_STYGIAN_IVORY) shr 2;                                    Barter: @BARTER_STYGIAN_IVORY),
                                (BarterCount: length(BARTER_SUNLIGHT_FILLED_MIRRORCATCH_BOX) shr 2;                  Barter: @BARTER_SUNLIGHT_FILLED_MIRRORCATCH_BOX),
                                (BarterCount: length(BARTER_SUPPLIES) shr 2;                                         Barter: @BARTER_SUPPLIES),
                                (BarterCount: length(BARTER_TALE_OF_TERROR) shr 2;                                   Barter: @BARTER_TALE_OF_TERROR),
                                (BarterCount: length(BARTER_THE_FIGUREHEAD_OF_THE_EATER_OF_NAMES) shr 2;             Barter: @BARTER_THE_FIGUREHEAD_OF_THE_EATER_OF_NAMES),
                                (BarterCount: length(BARTER_THE_HEART_OF_THE_TREE_OF_AGES) shr 2;                    Barter: @BARTER_THE_HEART_OF_THE_TREE_OF_AGES),
                                (BarterCount: length(BARTER_TOMB_COLONIST) shr 2;                                    Barter: @BARTER_TOMB_COLONIST),
                                (BarterCount: length(BARTER_TORPEDO_COMPONENTS) shr 2;                               Barter: @BARTER_TORPEDO_COMPONENTS),
                                (BarterCount: length(BARTER_UNREAD_LOG) shr 2;                                       Barter: @BARTER_UNREAD_LOG),
                                (BarterCount: length(BARTER_UNSTAMPED_CRATE_OF_BRILLIANT_SOULS) shr 2;               Barter: @BARTER_UNSTAMPED_CRATE_OF_BRILLIANT_SOULS),
                                (BarterCount: length(BARTER_UNSTAMPED_CRATE_OF_HUMAN_SOULS) shr 2;                   Barter: @BARTER_UNSTAMPED_CRATE_OF_HUMAN_SOULS),
                                (BarterCount: length(BARTER_UTTERSHROOM_SPOROULE) shr 2;                             Barter: @BARTER_UTTERSHROOM_SPOROULE),
                                (BarterCount: length(BARTER_VISION_OF_THE_SURFACE) shr 2;                            Barter: @BARTER_VISION_OF_THE_SURFACE),
                                (BarterCount: length(BARTER_WAKEFUL_IDOL) shr 2;                                     Barter: @BARTER_WAKEFUL_IDOL),
                                (BarterCount: length(BARTER_WATCHFUL_CURIO) shr 2;                                   Barter: @BARTER_WATCHFUL_CURIO),
                                (BarterCount: length(BARTER_ZEE_ZTORY) shr 2;                                        Barter: @BARTER_ZEE_ZTORY),
                                (BarterCount: length(BARTER_ZZOUP) shr 2;                                            Barter: @BARTER_ZZOUP));

  LocationNameEng:  array[0..30] of PWideChar=('Adam''s Way',
                                               'Aigul',
                                               'Anthe',
                                               'Cumaean Canal Staging Area',
                                               'Dahut',
                                               'Empire of hands',
                                               'Fallen London',
                                               'Gaider''s Mourn',
                                               'Gant Pole',
                                               'Hideaway',
                                               'Irem',
                                               'Iron Republic',
                                               'Isle of cats',
                                               'Khan''s Heart',
                                               'Khan''s Shadow',
                                               'Low Barnet',
                                               'Mount Palmerston',
                                               'Nook',
                                               'Polythreme',
                                               'Port Carnelian',
                                               'Prospering Wrack',
                                               'Rosegate',
                                               'Savior`s rock',
                                               'Scrimshander',
                                               'Station III',
                                               'Struggling Wrack',
                                               'The Chelonate',
                                               'Varchas',
                                               'Venderbight',
                                               'Whither',
                                               'Starting with');

  LocationNameRus:  array[0..30] of PWideChar=('Пролив Адама',
                                               'Айгуль',
                                               'Анфа',
                                               'Кумский канал',
                                               'Даут',
                                               'Империя рук',
                                               'Падший Лондон',
                                               'Печаль Гайдера',
                                               'Полюс Ганта',
                                               'Прибежище',
                                               'Ирем',
                                               'Железная республика',
                                               'Остров Кошек',
                                               'Сердце Хана',
                                               'Тень Хана',
                                               'Нижний Барнет',
                                               'Гора Палмерстон',
                                               'Бухта',
                                               'Полифем',
                                               'Порт Сердолик',
                                               'Процветающий Крах',
                                               'Роузгейт',
                                               'Скалы Спасителя',
                                               'Косторезы',
                                               'Станция III',
                                               'Борющийся Крах',
                                               'Черепашник',
                                               'Варчас',
                                               'Вендербайт',
                                               'Северные Дали',
                                               'Начинаем с');

  ShopNameEng: array[0..50] of PWideChar=('Peleghast''s Post',
                                          'Requisitions',
                                          'Stonemarket',
                                          'Dahut Exchange',
                                          'Mrs Plenty''s Shipside Provisioners',
                                          'Wolfstack Exchange',
                                          'Carrow''s Naval Surplus',
                                          'Caminus Yards',
                                          'The Iron & Misery Company',
                                          'Bultitude''s House of Vision',
                                          'The Alarming Scholar',
                                          'The Brass Embassy',
                                          'The Arrant Limpet',
                                          'The Friendly Face',
                                          'Jonah''s End',
                                          'Portentum',
                                          'Exile Bazaar',
                                          'The Fisher of Dawn',
                                          'Threshold',
                                          'Wind-Come-Calling',
                                          'Market of Hungers: Fire in the Belly',
                                          'The Calvary Doctrine: The House of Milks',
                                          'The Gesundheit Conspiracy:  House of Harvests',
                                          'The Parliament of Flies: House of Pleasures',
                                          'Expulsus: House of Harms',
                                          'Licensed Exchange',
                                          'Red Stallion Publishing',
                                          'Dearly Departed',
                                          'Traveller''s Friend',
                                          'Low Church',
                                          'Malebolge Excavations',
                                          'Daily Bread',
                                          'The Yawning Maw',
                                          'Temple of Labours',
                                          'Dockside Market',
                                          'Sapphire Exchange',
                                          'Proving Ground',
                                          'Remainder',
                                          'Uncle Ankle''s Lean Place',
                                          'Arcade of Sighs',
                                          'Hollow Temple',
                                          'The Charnel Lounge',
                                          'Fortune & Fortune',
                                          'The Hunter''s Cage',
                                          'Hull-harvest',
                                          'Harbour Provisioners',
                                          'Interaction',
                                          'Interaction (one time per a day)',
                                          'The Labyrinth of Tigers',
                                          'Surface',
                                          #0);

  ShopNameRus: array[0..50] of PWideChar=('Лавка Пелегаста',
                                          'Заявки',
                                          'Каменный рынок',
                                          'Обмен Даута',
                                          'Морская провизия от Миссис Пленти',
                                          'Обмен Вульфстака',
                                          'Морской магазин Кэрроу',
                                          'Кузница',
                                          'Компания ''Железо и Страдания''',
                                          'Дом Дальновидения Бултитуда',
                                          'Беспокойный студент',
                                          'Латунное посольство',
                                          'Отчаянный Моллюск',
                                          'Дружелюбное Лицо',
                                          'Окончание пути',
                                          'Предзнаменование',
                                          'Изгнанники Базара',
                                          'Ловец Рассвета',
                                          'Порог',
                                          'Зов Ветра',
                                          'Голодный Рынок: Огонь в Животе',
                                          'Доктрина Голгофы: Дом Молока',
                                          'Тайная подпольная организация ''Здоровье'': Дом Урожая',
                                          'Парламент мух: Дом Удовольствий',
                                          'Изгнание: Дом Ущерба',
                                          'Лицензированная торговля',
                                          'Издательство ''Красный Жеребец''',
                                          'Дорогие Усопшие',
                                          'Напарник Путешественника',
                                          'Нижняя Церковь',
                                          'Раскопки Малебольге',
                                          'Хлеб насущный',
                                          'Зияющая пасть',
                                          'Храм Труда',
                                          'Магазин на пристани',
                                          'Сапфировая биржа',
                                          'Испытательный полигон',
                                          'Наследие',
                                          'Закуток дяди Анкла',
                                          'Галерея вздохов',
                                          'Пустой храм',
                                          'Удобный склеп',
                                          'Счастье и Удача',
                                          'Пещера Охотнника',
                                          'Халл-сборщик',
                                          'Портовые поставщики',
                                          'Обмен',
                                          'Обмен (1 раз в день)',
                                          'Лабиринт тигров',
                                          'Поверхность',
                                          #0);

  ItemNameEng: array[0..61] of PWideChar=('A Casket of Sapphires',
                                          'A Firkin of Red Honey',
                                          'A Mirrorcatch Box Full of Very Angry Dream-Snakes',
                                          'A Pot of Violant Ink',
                                          'Ambiguous Eolith',
                                          'Approved Romantic Literature',
                                          'Bale of Parabola-Linen',
                                          'Bolts of Spider Silk',
                                          'Captivating Treasure',
                                          'Carboy of Primordial Shrieks',
                                          'Cask of Mushroom Wine',
                                          'Colossal Fluke-Core',
                                          'Crate of Human Souls',
                                          'Devilbone Dice',
                                          'Dread Surmise',
                                          'Drowning-Pearl',
                                          'Echo',
                                          'Empty Mirrorcatch Box',
                                          'Extraordinary Implication',
                                          'Firkin of Prisoner''s Honey',
                                          'Flare',
                                          'Foxfire Candles',
                                          'Fuel',
                                          'Harlot-Fry',
                                          'Hunter''s Eye',
                                          'Hunting Trophy',
                                          'Judgements'' Egg',
                                          'Lamentable Reloc',
                                          'Live Specimen',
                                          'Memory of Distant Shores',
                                          'Mountain-sherd',
                                          'Mt Nomad''s Heart',
                                          'Mutersalt',
                                          'Outlandish Artefact',
                                          'Romantic Literature',
                                          'Royal-Blue Feather',
                                          'Sack of Darkdrop Coffee Beans',
                                          'Scintillack',
                                          'Searing Enigma',
                                          'Secret',
                                          'Solacefruit',
                                          'Soothe & Cooper Long-Box',
                                          'Staion III: Hearthmetal Ignot',
                                          'Star-Shell',
                                          'Strange Catch',
                                          'Stygian Ivory',
                                          'Sunlight Filled Mirrorcatch Box',
                                          'Supplies',
                                          'Tale of Terror',
                                          'The Figurehead of the Eater of Names',
                                          'The Heart of the Tree of Ages',
                                          'Tomb-Colonist',
                                          'Torpedo Components',
                                          'Unread Log',
                                          'Unstamped Crate of Brilliant Souls',
                                          'Unstamped Crate of Human Souls',
                                          'Uttershroom Sporoule',
                                          'Vision of the Surface',
                                          'Wakeful Idol',
                                          'Watchful Curio',
                                          'Zee ztory',
                                          'Zzoup');

  ItemNameRus: array[0..61] of PWideChar=('Шкатулка сапфиров',
                                          'Бочонок Красного мёда',
                                          'Зеркальная ловушка, полная Очень злых Змей-Снов',
                                          'Флакон чернил цвета Виолант',
                                          'Неоднозначный Эолит',
                                          'Одобренная Любовная литература',
                                          'тюк Парабола-льна',
                                          'Рулон Паучьего шёлка',
                                          'Очаровательное сокровище',
                                          'Бутыль с Первобытными Визгами',
                                          'Бутыль грибного вина',
                                          'Сердце Колоссального Бродячего Ежа',
                                          'Ящик человеческих душ',
                                          'Дьявольские кубики',
                                          'Ужасная догадка',
                                          'Жемчуг Утопца',
                                          'Эхо',
                                          'Пустая Зеркальная ловушка',
                                          'Чрезвычайные результаты',
                                          'Бочонок арестантского мёда',
                                          'Сигнальная ракета',
                                          'Фосфоресцирующие свечи',
                                          'Топливо',
                                          'Блудная мелюзга',
                                          'Глаз Охотника',
                                          'Охотничий Трофей',
                                          'Яйцо Наказания',
                                          'Печальные останки',
                                          'Живая особь',
                                          'Память о дальних берегах',
                                          'Горный Осколок',
                                          'Сердце горы Кочевник',
                                          'Мутерсоль',
                                          'Диковинный артефакт',
                                          'Любовная литература',
                                          'Лазурное перо',
                                          'Мешок зёрен Тёмного Кофе',
                                          'Сцинтиллак',
                                          'Жгучая загадка',
                                          'Секрет',
                                          'Успокой-фрукт',
                                          'Длинный ящик фирмы ''Успокой и Плотник''',
                                          'Станция III: Железносердечный Слиток',
                                          'Звёздная оболочка',
                                          'Подозрительный улов',
                                          'Стигийская слоновая кость',
                                          'Зеркальная ловушка, полная Солнечного света',
                                          'Припасы',
                                          'Сказка об Ужасе!!',
                                          'Носовая фигура с ''Пожирателя Имён''',
                                          'Сердце Древа Веков',
                                          'Гробо-колонист',
                                          'Торпеда',
                                          'Непрочитанный Журнал',
                                          'Непроштампованный ящик выдающихся человеческих душ',
                                          'Непроштампованный ящик человеческих душ',
                                          'Споры Грибнища',
                                          'Вид Поверхности',
                                          'Бессонный Идол',
                                          'Бдительная Фигурка',
                                          'Морская история',
                                          'Зупчик');
