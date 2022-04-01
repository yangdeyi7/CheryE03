/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : Sensor                                                  */
/*                                                                            */
/* !Component       : Sensor                                                  */
/* !Description     : Provides interface for sensor management                */
/*                                                                            */
/* !Module          : Sensor                                                  */
/* !Description     : Provides interface for sensor management                */
/*                                                                            */
/* !File            : Sensor.c                                                */
/*                                                                            */
/* !Scope           : Private                                                 */
/*                                                                            */
/* !Target          : uPD70F3375                                              */
/*                                                                            */
/* !Vendor          : T13 (VALEO Climate Control China)                       */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2017 VALEO                                                       */
/* All Rights Reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/EC$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/ECUAL/Sensor.c-arc  $
* 
*    Rev 1.1   Dec 18 2017 15:24:20   chunping.yan
* Add signal 0x538
* 
*    Rev 1.1   Jun 30 2017 18:19:12   chunping.yan
* standardization
* 
*    Rev 1.0   Jun 30 2017 09:47:22   CYAN
* Initial revision.
* 
* 
******************************************************************************/
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Sensor.h"
#include "ADC.h"
#include "TAB.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/
static const TAB16 SEN_akstrEvaptab[] =
{
    /*--ADC--------EVAP_T_Sen*10----*/
 32767,          -400,
   924,          -400,
   891,          -350,
   850,          -300,
   801,          -250,
   745,          -200,
   684,          -150,
   618,          -100,
   551,           -50,
   485,             0,
   422,            50,
   363,           100,
   309,           150,
   262,           200,
   221,           250,
   186,           300,
   156,           350,
   131,           400,
   110,           450,
    93,           500,
    78,           550,
    66,           600,
    56,           650,
    47,           700,
    40,           750,
    34,           800,
    29,           850,
-32768,           850, 
};
/******************************************************************************/
static const TAB16  Sensor_akstrWater_SenT[] = {
    /*--ADC--------WAT_T_Sen*10----*/
    32767,          -400,
    839,          -400,
    793,          -350,
    740,          -300,
    683,          -250,
    622,          -200,
    559,          -150,
    496,          -100,
    436,           -50,
    380,             0,
    328,            50,
    281,           100,
    240,           150,
    205,           200,
    175,           250,
    149,           300,
    127,           350,
    108,           400,
    92,           450,
    79,           500,
    67,           550,
    58,           600,
    50,           650,
    43,           700,
    37,           750,
    32,           800,
    28,           850,
    24,           900,
    21,           950,
    19,          1000,
    17,          1050,
    15,          1100,
    13,          1150,
    11,          1200,
    10,          1250,
    9,          1300,
    8,          1350,
    7,          1400,
    7,          1450,
    6,          1500,
    -32768,          1500,
};
/******************************************************************************/
static const TAB16  Sensor_akstrAmb_SenT[] = {
    /*--ADC--------AMB_T_Sen*10----*/
    32767,          -400,
    933,          -400,
    901,          -350,
    863,          -300,
    816,          -250,
    763,          -200,
    704,          -150,
    640,          -100,
    574,           -50,
    508,             0,
    443,            50,
    383,           100,
    328,           150,
    279,           200,
    236,           250,
    199,           300,
    167,           350,
    141,           400,
    119,           450,
    100,           500,
    84,           550,
    71,           600,
    61,           650,
    51,           700,
    44,           750,
    37,           800,
    32,           850,
    28,           900,
    24,           950,
    21,          1000,
    -32768,      1000,
};
/******************************************************************************/
static const TAB16  Sensor_akstrIncar_SenT[] = {
    /*--ADC--------incar_T_Sen*10----*/
 32767,          -400,
   832,          -400,
   732,          -300,
   616,          -200,
   495,          -100,
   384,             0,
   289,           100,
   214,           200,
   157,           300,
   115,           400,
    85,           500,
    63,           600,
    55,           700,
    36,           800,
    27,           900,
    21,          1000,
-32768,          1000,

};
/******************************************************************************/
static const TAB16  Sensor_akstrDuct_SenT[] = {
    /*--ADC--------DUCT_T_Sen*10----*/
    32767,          -400,
    994,          -400,
    983,          -350,
    969,          -300,
    951,          -250,
    928,          -200,
    901,          -150,
    867,          -100,
    828,           -50,
    784,             0,
    735,            50,
    682,           100,
    626,           150,
    569,           200,
    512,           250,
    457,           300,
    405,           350,
    356,           400,
    311,           450,
    271,           500,
    235,           550,
    204,           600,
    177,           650,
    153,           700,
    132,           750,
    114,           800,
    99,           850,
    -32768,           850,
};
/******************************************************************************/
static const TAB16  Sensor_akstrLP_T_SenT[] = {
#if 1
    /*--ADC--------LP_T_Sen*10----*/
 32767,          -400,
   991,          -400,
   964,          -300,
   922,          -200,
   860,          -100,
   775,             0,
   675,           100,
   565,           200,
   454,           300,
   353,           400,
   270,           500,
   203,           600,
   152,           700,
   113,           800,
    85,           900,
    64,          1000,
    49,          1100,
    37,          1200,
    29,          1300,
    22,          1400,
    18,          1500,
-32768,          1500,
#else //集成模块上的LV_T
    32767,          -300,
    733,          -300,
    666,          -250,
    595,          -200,
    522,          -150,
    452,          -100,
    386,           -50,
    326,             0,
    273,            50,
    227,           100,
    188,           150,
    155,           200,
    128,           250,
    106,           300,
    87,           350,
    72,           400,
    60,           450,
    50,           500,
    -32768,           500,
#endif
};
/******************************************************************************/
static const TAB16  Sensor_akstrLP_P_SenT[] = {
    /*--ADC--------LP_P_Sen(Bar)*10----*/
    -32768,             0,
    51,             0,
    136,            10,
    221,            20,
    306,            30,
    391,            40,
    476,            50,
    560,            60,
    645,            70,
    730,            80,
    815,            90,
    900,           100,
    985,           110,
    32767,           110,
};
/******************************************************************************/
static const TAB16  Sensor_akstrHP_P_SenT[] = {
#if 1
    /*--ADC--------HP_P_Sen(Bar)*10----*/
    -32768,             0,
    20,             0,
    36,             5,
    51,            10,
    66,            15,
    81,            20,
    96,            25,
    172,            50,
    324,           100,
    476,           150,
    628,           200,
    780,           250,
    932,           300,
    993,           320,
    32767,           320,
#else //集成模块上的HP
    -32768,             0,
    34,             0,
    48,             5,
    62,            10,
    76,            15,
    90,            20,
    104,            25,
    173,            50,
    312,           100,
    451,           150,
    590,           200,
    728,           250,
    867,           300,
    923,           320,
    32767,           320,
#endif
};

/******************************************************************************/
static const uint16  Sensor_ku16DefaultVal[] = 
{
    250,
    250,
    250,
    250,
    250,
    250,
    250,
    250,
    250,
    250,
    100,
    100,
    100,
};

/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/


/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/


/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/
static Sensor_tuniSampleValue  Sensor_uniSampleValue;
static Sensor_tenuStatus       Sensor_au8Check[Sensor_u8NUM];
//uint16   u16sensor_testlv; 
//uint16   u16sensor_testrv; 
//uint16   u16sensor_testlf; 
//uint16   u16sensor_testrf;
//uint16   u16sensor_testwater1;
//uint16   u16sensor_testwater2;
uint16   u16sensor_testhp1;
uint16   u16sensor_testhp2;
uint16   u16sensor_testlpp;
uint16   u16sensor_testlpt;
uint16   u16sensor_testamb;
uint16   u16sensor_testincar;
uint16   u16sensor_testeva;
/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/
static void  vidStatusCheckAndDataGet(uint8 u8Id);

/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/

/******************************************************************************/
/*!Function:   vidStatusCheckAndDataGet*/
/*! \Description Check Sensor connect status and Get Sensor Data . \n
\Return      void.
\Trace_To    CDD-Sensor-  
*******************************************************************************/
static void  vidStatusCheckAndDataGet(uint8 u8Id)
{
    static uint16 LOC_au16SampVal[Sensor_u8NUM];
    const TAB16 *pstrSensTab;
    
    /******************************************************************************/
    if (Sensor_u8EVAP == u8Id )
    {
      u16sensor_testeva = Adc_u16Read(ADC_u8AI1_J2_13);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI1_J2_13);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16EvapSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8EVAP]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16EvapSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8EVAP];
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = SEN_akstrEvaptab ;
            Sensor_uniSampleValue.strSampleValue.s16EvapSensorValue =  LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);      
        }
    }  
    /******************************************************************************/
    else if (Sensor_u8WATER1 == u8Id )
    {
    //u16sensor_testwater1 = Adc_u16Read(ADC_u8AI8_J2_20);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI8_J2_20);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16Water1SensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8WATER1]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16Water1SensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8WATER1]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrWater_SenT ;
            Sensor_uniSampleValue.strSampleValue.s16Water1SensorValue  = LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);      
        }
    }
    /******************************************************************************/
    else if (Sensor_u8WATER2 == u8Id )
    {
    //u16sensor_testwater2 = Adc_u16Read(ADC_u8AI11_J3_3);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI11_J3_3);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16Water2SensorValue =  
                Sensor_ku16DefaultVal[Sensor_u8WATER2]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16Water2SensorValue =   
                Sensor_ku16DefaultVal[Sensor_u8WATER2]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrWater_SenT ;
            Sensor_uniSampleValue.strSampleValue.s16Water2SensorValue  = LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);      
        }
    }
    /******************************************************************************/
    else if ( Sensor_u8AMB == u8Id )
    {
    //u16sensor_testamb = Adc_u16Read(ADC_u8AI6_J2_18);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI6_J2_18);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16AmbSensorValue =  
                Sensor_ku16DefaultVal[Sensor_u8AMB]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16AmbSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8AMB]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrAmb_SenT ;
            Sensor_uniSampleValue.strSampleValue.s16AmbSensorValue = LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);      
        }
    }
    /******************************************************************************/
    else if (Sensor_u8INCAR == u8Id )
    {
      u16sensor_testincar = Adc_u16Read(ADC_u8AI7_J2_19);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI7_J2_19);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16IncarSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8INCAR]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16IncarSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8INCAR]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrIncar_SenT;
            Sensor_uniSampleValue.strSampleValue.s16IncarSensorValue  = LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);  
        }
    }
    /******************************************************************************/
    else if (Sensor_u8TDUCT_L_V == u8Id )
    {
    //u16sensor_testlv = Adc_u16Read(ADC_u8AI2_J2_14);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI2_J2_14);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16DuctLVSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_L_V]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16DuctLVSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_L_V]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrDuct_SenT;
            Sensor_uniSampleValue.strSampleValue.s16DuctLVSensorValue  =  LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);  
        }
    }
    /******************************************************************************/
    else if (Sensor_u8TDUCT_R_V == u8Id )
    {
    //u16sensor_testrv = Adc_u16Read(ADC_u8AI3_J2_15);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI3_J2_15);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16DuctRVSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_R_V]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16DuctRVSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_R_V]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrDuct_SenT;
            Sensor_uniSampleValue.strSampleValue.s16DuctRVSensorValue  = LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);  
        }
    }
    /******************************************************************************/
    else if (Sensor_u8TDUCT_L_F == u8Id )
    {
    //u16sensor_testlf = Adc_u16Read(ADC_u8AI4_J2_16);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI4_J2_16);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16DuctLFSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_L_F]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16DuctLFSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_L_F]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrDuct_SenT;
            Sensor_uniSampleValue.strSampleValue.s16DuctLFSensorValue  = LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);  
        }
    }
    /******************************************************************************/
    else if (Sensor_u8TDUCT_R_F == u8Id )
    {
    //u16sensor_testrf = Adc_u16Read(ADC_u8AI5_J2_17);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI5_J2_17);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16DuctRFSensorValue  = 
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_R_F]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16DuctRFSensorValue  =  
                Sensor_ku16DefaultVal[Sensor_u8TDUCT_R_F]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrDuct_SenT;
            Sensor_uniSampleValue.strSampleValue.s16DuctRFSensorValue  =  LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);  
        }
    }
    /******************************************************************************/
    else if (Sensor_u8LP_T == u8Id )
    {
    u16sensor_testlpt = Adc_u16Read(ADC_u8AI_SUN_L_J2_12);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI_SUN_L_J2_12);
        /*  the sensor is short. */
        if(LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_GND; 
            Sensor_uniSampleValue.strSampleValue.s16LPTSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8LP_T]; 
        }
        /* the sensor is open.*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16LPTSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8LP_T]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrLP_T_SenT;
            Sensor_uniSampleValue.strSampleValue.s16LPTSensorValue = 
            LinRevInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);  
        }
    }
    /******************************************************************************/
    else if(Sensor_u8LP_P == u8Id )
    {
    u16sensor_testlpp = Adc_u16Read(ADC_u8AI14_J3_6);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI14_J3_6);
        /*  the pressure sensor is open.
        (refer to SCH different from other sensers)*/
        if (LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16LPPSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8LP_P]; 
        }
        /* the sensor is short to vcc.
        (refer to SCH different from other sensers)*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_VCC;
            Sensor_uniSampleValue.strSampleValue.s16LPPSensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8LP_P]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrLP_P_SenT ;
            Sensor_uniSampleValue.strSampleValue.s16LPPSensorValue = 
                LinInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab);     
        }
    }
    /******************************************************************************/
    else if(Sensor_u8HP_P1 == u8Id )
    {
    u16sensor_testhp1 = Adc_u16Read(ADC_u8AI15_J3_13);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI15_J3_13);
        /*  the pressure sensor is open.
        (refer to SCH different from other sensers)*/
        if (LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN; 
            Sensor_uniSampleValue.strSampleValue.s16HP1SensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8HP_P1]; 
        }
        /* the sensor is short to vcc.
        (refer to SCH different from other sensers)*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_VCC;
            Sensor_uniSampleValue.strSampleValue.s16HP1SensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8HP_P1]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrHP_P_SenT ;
            Sensor_uniSampleValue.strSampleValue.s16HP1SensorValue = 
                LinInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab)+10u;     
        }
    }
    /******************************************************************************/
    else if(Sensor_u8HP_P2 == u8Id )
    {
    u16sensor_testhp2 = Adc_u16Read(ADC_u8AI12_J3_4);
        LOC_au16SampVal[u8Id] = Adc_u16Read(ADC_u8AI12_J3_4);
        /*  the pressure sensor is open.
        (refer to SCH different from other sensers)*/
        if (LOC_au16SampVal[u8Id] < Sensor_u8LOWERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_OPEN;
            Sensor_uniSampleValue.strSampleValue.s16HP2SensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8HP_P2]; 
        }
        /* the sensor is short to vcc.
        (refer to SCH different from other sensers)*/
        else if (LOC_au16SampVal[u8Id] > Sensor_u8UPPERLIMIT_ADC)
        {
            Sensor_au8Check[u8Id] = Sensor_SHORT_VCC;
            Sensor_uniSampleValue.strSampleValue.s16HP2SensorValue = 
                Sensor_ku16DefaultVal[Sensor_u8HP_P2]; 
        }
        else
        {
            Sensor_au8Check[u8Id] = Sensor_NORMAL;
            pstrSensTab = Sensor_akstrHP_P_SenT ;
            Sensor_uniSampleValue.strSampleValue.s16HP2SensorValue =  
                LinInterpolation16(LOC_au16SampVal[u8Id], pstrSensTab)+10u;
        }
    }
    /******************************************************************************/
    /*others*/
    else
    {
        
    }
    
}


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/
/******************************************************************************/
/*!Function:   Sensor_vidInit                                                 */
/*! \Description Sensor Initialization service. \n
\Return      void.
\Trace_To    CDD-Sensor-  
*******************************************************************************/
extern void Sensor_vidInit( void )
{
    uint8 u8Index;	
    /*! Initial the array to default value */
    for (u8Index = 0 ; u8Index < Sensor_u8NUM ;u8Index++)
    {
	Sensor_uniSampleValue.s16DataAll[u8Index] = Sensor_ku16DefaultVal[u8Index];
        Sensor_au8Check[u8Index] = Sensor_UNKNOWN;
    } 
}/* End of Sensor_vidInit() */


/******************************************************************************/
/*!Function:   Sensor_s16Read                                           */
/*! \Description App read different channel sample value. \n
\param[in]   u8Id : ID of data
\Range       0...9  \n
\return      read value     \n
\Trace_To    CDD-Sensor-  
*******************************************************************************/
extern sint16 Sensor_s16Read( uint8 u8Id )
{ 
    sint16 s16ReadResult;
    /*! if ID is in range */
    if ( u8Id < Sensor_u8NUM )
    {
        /*! return conversion value of certain ID */
        //s16ReadResult = Sensor_as16ConversionResult[u8Id];
        s16ReadResult = Sensor_uniSampleValue.s16DataAll[u8Id];
    }
    /*! else */
    else 
    { 
        /*! return 0 */
        s16ReadResult = (sint8)0;
    }
    return s16ReadResult ;
}/* End of Sensor_s16Read */



/******************************************************************************/
/*!Function:   Sensor_vidManage                                               */
/*! \Description Manage all the Sensor value. \n
\Return      void.
\Trace_To    CDD-Sensor-
*******************************************************************************/
extern void Sensor_vidManage(void)
{
    uint8 u8IndexSenId;
    for(u8IndexSenId = 0; u8IndexSenId < Sensor_u8NUM; u8IndexSenId ++)
    {	
        vidStatusCheckAndDataGet( u8IndexSenId );
        if( Sensor_u8NUM == u8IndexSenId )
        {
            u8IndexSenId = 0;
        }
    }
}   /* End of Sensor_vidManage()  */


/******************************************************************************/
/*!Function:  Sensor_enuGetCurrentStatus                                                */
/*! \Description return the sensor current status. \n
\Return      sensor current status.
\Trace_To   CDD-Sensor-  
*******************************************************************************/
extern Sensor_tenuStatus Sensor_enuGetCurrentStatus( uint8 u8Id )
{
    return Sensor_au8Check[u8Id];	
}/* End of Sensor_enuGetCurrentStatus()  */













