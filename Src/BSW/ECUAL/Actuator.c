/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/
#include "Std_Types.h"
#include "Actuator.h"
#include "TLE9410xDrv.h"
#include "Adc.h"

#define   s8ABS_DIFF(x ,y)  ( ((x) > (y)) ? ((x) - (y)) : ((y) - (x)) )


static uint8                        Actuator_au8CurPos[u8ACT_NUM];
static uint8                        Actuator_au8DesPos[u8ACT_NUM];
static Actuator_tenuFailureState    Actuator_aenuFailureState[u8ACT_NUM];
static Actuator_tenuState           Actuator_aenuState[u8ACT_NUM] ;
static boolean                      Actuator_abEnableManage[u8ACT_NUM];

/*Actuator Position ADC Value from EEP or Default Backup Data*/
static uint16                       Actuator_au16PosLow[u8ACT_NUM];
static uint16                       Actuator_au16PosHigh[u8ACT_NUM];

/* local functions declaration */
static void Actuator_vidRunCW(uint8 u8ActId);
static void Actuator_vidBrake(uint8 u8ActId);
static void Actuator_vidRunCCW(uint8 u8ActId);



void Actuator_vidStop(uint8 u8ActId)
{
   switch(u8ActId)
   {
     case u8ACT_MIXL:
	   TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXL,0,0);
       break;
     case u8ACT_MIXR:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXR,0,0);
       break;
	 case u8ACT_MODEL:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODEL,0,0);
       break;
	 case u8ACT_MODER:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODER,0,0);
       break; 
	 case u8ACT_DEFROST:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_DEFROST,0,0);
       break;
     case u8ACT_RECY:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_RECY,0,0);
       break;

     default:
       break;
   }
   Actuator_aenuState[u8ActId] = Actuator_STOP ;
}

static void Actuator_vidBrake(uint8 u8ActId)
{
   switch(u8ActId)
   {
     case u8ACT_MIXL:
	   TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXL,1,1);
       break;
     case u8ACT_MIXR:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXR,1,1);
       break;
	 case u8ACT_MODEL:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODEL,1,1);
       break;
	 case u8ACT_MODER:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODER,1,1);
       break; 
	 case u8ACT_DEFROST:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_DEFROST,1,1);
       break;
     case u8ACT_RECY:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_RECY,1,1);
       break;
     default:
       break;
   }
   Actuator_aenuState[u8ActId] = Actuator_BRAKE ;
}

 
static void Actuator_vidRunCW(uint8 u8ActId)    
{
   switch(u8ActId)
   {
     case u8ACT_MIXL:
	   TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXL,1,0);
       break;
     case u8ACT_MIXR:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXR,1,0);
       break;
	 case u8ACT_MODEL:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODEL,1,0);
       break;
	 case u8ACT_MODER:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODER,1,0);
       break; 
	 case u8ACT_DEFROST:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_DEFROST,1,0);
       break;
     case u8ACT_RECY:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_RECY,1,0);
       break;
     default:
       break;
   }
   Actuator_aenuState[u8ActId] = Actuator_CW ;  
}


    
static void Actuator_vidRunCCW(uint8 u8ActId)    
{
   switch(u8ActId)
   {
     case u8ACT_MIXL:
	   TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXL,0,1);
       break;
     case u8ACT_MIXR:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MIXR,0,1);
       break;
	 case u8ACT_MODEL:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODEL,0,1);
       break;
	 case u8ACT_MODER:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_MODER,0,1);
       break; 
	 case u8ACT_DEFROST:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_DEFROST,0,1);
       break;
     case u8ACT_RECY:
       TLE9410xDrv_vidDcMotorCtrl(TLE9410XDRV_RECY,0,1);
       break;
     default:
       break;
   }
   Actuator_aenuState[u8ActId] = Actuator_CCW ; 
}


Actuator_tenuState Actuator_enuGetRunState(uint8 u8ActId)
{
  return Actuator_aenuState[u8ActId];
}


void Actuator_vidInit(void)
{  
  uint8 u8Index;
  const uint8 kau8ActHighPos1[u8ACT_NUM] = {  3,      3,     3,    3,   3,   3};
  const uint8 kau8ActHighPos2[u8ACT_NUM] = { 59,     59,   180,  180,  46,  83};
  const uint8 kau8ActLowPos1[u8ACT_NUM]  = {  0,      0,     0,    0,   0,   1};
  const uint8 kau8ActLowPos2[u8ACT_NUM]  = {235,    235,   170,  190, 194, 172};
  for(u8Index = 0; u8Index < u8ACT_NUM; u8Index++)
  {
      Actuator_abEnableManage[u8Index] = TRUE;
      Actuator_au8CurPos[u8Index]= 0u;
      Actuator_au8DesPos[u8Index]= 0u; 
      Actuator_au16PosHigh[u8Index] = kau8ActHighPos1[u8Index]*256u + kau8ActHighPos2[u8Index];
      Actuator_au16PosLow[u8Index]  = kau8ActLowPos1[u8Index]*256u  + kau8ActLowPos2[u8Index];
      Actuator_vidStop(u8Index);
  }

 }


void Actuator_vidEnableManage(uint8 u8ActId,boolean bEn)
{
    Actuator_abEnableManage[u8ActId] = bEn;
    if(Actuator_abEnableManage[u8ActId]== FALSE)
    {
       Actuator_vidStop(u8ActId);
    }
}
uint16 motor_test;
void Actuator_vidManage(uint8 u8ActId)
{
  static uint16  LOC_au16CntRunTimeout[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16Cnt[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16CntStall[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
  static sint16  LOC_as16LastDesPos[u8ACT_NUM] = {-1,-1,-1,-1,-1,-1};
  static uint16  LOC_au16Run[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16PreRecADC[u8ACT_NUM] =  {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16TryTimes[u8ACT_NUM]  =  {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16DelayCnt[u8ACT_NUM]  =  {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16CurPosiAdc[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
  static uint16  LOC_au16DesPosiAdc[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
         sint16  s16Tmp = 0;
		 sint16  s16CurrStroke = 0;
         sint16  s16AllStroke = 0;
  
  if(LOC_au16DelayCnt[u8ActId] < 10u)
  {
      LOC_au16DelayCnt[u8ActId]++;
      return;
  }
  if(Actuator_abEnableManage[u8ActId]==FALSE) // if App Notify Stop Actuator
  {
      return;
  }
  /*get current position : ADC value*/
  switch(u8ActId)
  {
       case u8ACT_MIXL:
	     LOC_au16CurPosiAdc[u8ActId] = Adc_u16Read(ADC_u8MIXL_ID);//
       break;
       
      case u8ACT_MIXR:
	     LOC_au16CurPosiAdc[u8ActId] = Adc_u16Read(ADC_u8MIXR_ID);
       break;

      case u8ACT_MODEL:
         LOC_au16CurPosiAdc[u8ActId] = Adc_u16Read(ADC_u8MODEL_ID);
       break;

	  case u8ACT_MODER:
         LOC_au16CurPosiAdc[u8ActId] = Adc_u16Read(ADC_u8MODER_ID);
       break;  

	  case u8ACT_DEFROST:
         LOC_au16CurPosiAdc[u8ActId] = Adc_u16Read(ADC_u8DEFORST_ID);
       break;
       
      case u8ACT_RECY:
         LOC_au16CurPosiAdc[u8ActId] = Adc_u16Read(ADC_u8RECY_ID);
         motor_test = LOC_au16CurPosiAdc[u8ActId];
       break;
	   
      default:
      break;
  }
  /*get current position : % precent*/
  if(Actuator_au16PosHigh[u8ActId] == Actuator_au16PosLow[u8ActId])
  {
    s16Tmp = 0;	  
  }
  else
  {  
    s16AllStroke = Actuator_au16PosHigh[u8ActId] - Actuator_au16PosLow[u8ActId];
    s16CurrStroke = LOC_au16CurPosiAdc[u8ActId]- Actuator_au16PosLow[u8ActId];
	/****************************calc Porcess*********************************/
	/*
	  ===>s16Tmp = s16CurrStroke * 100 / s16AllStroke
	  ===>s16Tmp = s16CurrStroke * 100 / s16AllStroke + 1/2 ( decimals is <=4 omit, >=5 plus 0.5 )
	  ===>s16Tmp = s16CurrStroke * 100 / s16AllStroke + (s16AllStroke / 2*s16AllStroke)
	  ===>s16Tmp = (s16CurrStroke*200 + s16AllStroke) / (s16AllStroke*2)) ; 
	*/
    s16Tmp = (sint16)((sint32)(s16CurrStroke*200 + s16AllStroke) / (sint32)(s16AllStroke*2)) ; 
  } 
  if(s16Tmp < 0)
  {
     s16Tmp = 0;
  }
  else if(s16Tmp > 100)
  {
     s16Tmp = 100;
  }
  else
  {
    
  }
  Actuator_au8CurPos[u8ActId] = s16Tmp;
  
  /*get dest position : ADC value*/
  LOC_au16DesPosiAdc[u8ActId] = Actuator_au8DesPos[u8ActId]*(Actuator_au16PosHigh[u8ActId] - Actuator_au16PosLow[u8ActId])/100 + Actuator_au16PosLow[u8ActId];

  /*ACT move only under this case: setting dest position change*/
  if( LOC_as16LastDesPos[u8ActId] != Actuator_au8DesPos[u8ActId])
  {
	LOC_au16CntRunTimeout[u8ActId] = 0u;
	LOC_au16Cnt[u8ActId] = 0u;
	LOC_au16Run[u8ActId] = 1u;
	LOC_au16CntStall[u8ActId] = 0u;
	LOC_as16LastDesPos[u8ActId] = Actuator_au8DesPos[u8ActId];
	LOC_au16PreRecADC[u8ActId] = LOC_au16CurPosiAdc[u8ActId];
	
	/*check running direction*/
	if(LOC_au16CurPosiAdc[u8ActId] < LOC_au16DesPosiAdc[u8ActId])
	{
         Actuator_vidRunCCW(u8ActId);
	}
	else if(LOC_au16CurPosiAdc[u8ActId] > LOC_au16DesPosiAdc[u8ActId])
	{
         Actuator_vidRunCW(u8ActId);
	}
	else
	{
	     Actuator_vidBrake(u8ActId);
	     LOC_au16Cnt[u8ActId] = 0u;
	}
	LOC_au16TryTimes[u8ActId] = 0u;
  }
  else/*des pos not change , to check if adc value within tolerance:*/
  {
      /*check if act stop */
      if(Actuator_aenuState[u8ActId] == Actuator_STOP)
      {
          /*check dest pos = cur pos ? max 3 times*/
          s16Tmp=LOC_au16CurPosiAdc[u8ActId]-LOC_au16DesPosiAdc[u8ActId];
          if(s16Tmp < -15 || s16Tmp > 15)
          {
              if(LOC_au16TryTimes[u8ActId] < 30u)
              {
                  LOC_au16CntRunTimeout[u8ActId] = 0u;
                  LOC_au16Cnt[u8ActId] = 0u;
                  LOC_au16Run[u8ActId] = 1u;
                  LOC_au16CntStall[u8ActId] = 0u;
                  LOC_as16LastDesPos[u8ActId] = Actuator_au8DesPos[u8ActId];
                  LOC_au16PreRecADC[u8ActId] = LOC_au16CurPosiAdc[u8ActId];
                  /*check running direction*/
                  if(LOC_au16CurPosiAdc[u8ActId] < LOC_au16DesPosiAdc[u8ActId])
                  {
                      Actuator_vidRunCCW(u8ActId);
                  }
                  else if(LOC_au16CurPosiAdc[u8ActId] > LOC_au16DesPosiAdc[u8ActId])
                  {
                      Actuator_vidRunCW(u8ActId);
                  }
                  else
                  {
                      Actuator_vidBrake(u8ActId);
                      LOC_au16Cnt[u8ActId] = 0;
                  }				  
                  LOC_au16TryTimes[u8ActId]++;
              }
          }
       }
   }

  /*=============================================================================*/
  /*running time : time out check: if time out ->stop*/
  if(LOC_au16CntRunTimeout[u8ActId] < 1500u)
  {
      LOC_au16CntRunTimeout[u8ActId]++ ;
  }
  else //time out >=15s
  {
     Actuator_vidStop(u8ActId);
     LOC_au16Run[u8ActId] = 0u;
  }
  if(LOC_au16Run[u8ActId] == 0u)
  {
     return;
  }

  /*=============================================================================*/
  /*check if current pos==dest pos, if within adc 3 then stop*/
  if(Actuator_CW == Actuator_aenuState[u8ActId])
  {
	 //paramaters need to adjust use actual HVAC
     if(LOC_au16CurPosiAdc[u8ActId] <= (LOC_au16DesPosiAdc[u8ActId] + 3u))
     {
        Actuator_vidBrake(u8ActId);
	    LOC_au16Cnt[u8ActId] = 0u;
     }
  }  
  else if (Actuator_CCW == Actuator_aenuState[u8ActId])
  {
	  //paramaters need to adjust use actual HVAC
     if((LOC_au16CurPosiAdc[u8ActId] + 3u) >= LOC_au16DesPosiAdc[u8ActId])
     {
        Actuator_vidBrake(u8ActId);
	    LOC_au16Cnt[u8ActId] = 0u;
     }
  }
  else if(Actuator_BRAKE == Actuator_aenuState[u8ActId])
  {
     LOC_au16Cnt[u8ActId]++;
     if(LOC_au16Cnt[u8ActId] > 10u)
     {
	     LOC_au16Cnt[u8ActId] = 0u;
         Actuator_vidStop(u8ActId);
     }
  }
  else if(Actuator_STOP == Actuator_aenuState[u8ActId])
  {
     LOC_au16Run[u8ActId] = 0u;
  }
  else
  {
    
  }

  /*********************Stall Check***************************************/	 
  /*check stall status by every 2s*/
  LOC_au16CntStall[u8ActId]++;
  if(LOC_au16CntStall[u8ActId] > 200u) 
  {
      s16Tmp = LOC_au16CurPosiAdc[u8ActId] - LOC_au16PreRecADC[u8ActId];
      if(Actuator_CW == Actuator_aenuState[u8ActId])
      {
          //s16Tmp should be >0
          if(s16Tmp < 5)
          {
            //stalled
            Actuator_vidStop(u8ActId);
            LOC_au16Run[u8ActId] = 0u;
          }
      }
      else if(Actuator_CCW == Actuator_aenuState[u8ActId])
      {
          //s16Tmp should be <0
          if(s16Tmp > -5)
          {
            //stalled
            Actuator_vidStop(u8ActId);
            LOC_au16Run[u8ActId] = 0u;
          }
      }
      else
      {
        
      }
      LOC_au16PreRecADC[u8ActId] = LOC_au16CurPosiAdc[u8ActId];
      LOC_au16CntStall[u8ActId] = 0u;
  }

}


void Actuator_vidSetPosition(uint8 u8ActId,uint8 u8Percent)
{
    if(u8Percent <= 100u)
    {
        Actuator_au8DesPos[u8ActId] = u8Percent; 
    }
}
uint8 Actuator_u8GetPosition(uint8 u8ActId)
{
    uint8 u8ActCurrPosi = 0u;
    u8ActCurrPosi = Actuator_au8CurPos[u8ActId];
    return (u8ActCurrPosi);
}

uint8 Actuator_u8GetModeLStatusMathWithMbd(void)
{
    uint8 u8CurrModeLStsPosi = 0xffu;
	
	u8CurrModeLStsPosi = Actuator_au8CurPos[u8ACT_MODEL];
	if(s8ABS_DIFF(u8CurrModeLStsPosi ,u8MODEL_VENT) <= 2)
	{
       u8CurrModeLStsPosi = 1;//vent
	}
	else if(s8ABS_DIFF(u8CurrModeLStsPosi ,u8MODEL_FOOT) <= 2)
	{
       u8CurrModeLStsPosi = 3;//foot
	}
	else if(s8ABS_DIFF(u8CurrModeLStsPosi ,u8MODEL_VENT) <= 2)
	{
       u8CurrModeLStsPosi = 5;//foot
	}
	else
	{

	}
	return u8CurrModeLStsPosi;
	

}

Actuator_tenuModeLState Actuator_enuGetModeLStatus(void)
{
	static Actuator_tenuModeLState LOC_enuModeLState = MODEL_UNKNOWN;
    uint8 u8ModeLActCurrPosi = 0u;
    u8ModeLActCurrPosi = Actuator_au8CurPos[u8ACT_MODEL];
	if(s8ABS_DIFF(u8ModeLActCurrPosi ,u8MODEL_VENT) <= 2)
	{
       LOC_enuModeLState = MODEL_VENT;
	}
	else if(s8ABS_DIFF(u8ModeLActCurrPosi ,u8MODEL_FOOT) <= 2)
	{
       LOC_enuModeLState = MODEL_FOOT;
	}
	else if(s8ABS_DIFF(u8ModeLActCurrPosi ,u8MODEL_DEF) <= 2)
	{
       LOC_enuModeLState = MODEL_DEF;
	}
	else 
	{
       LOC_enuModeLState = MODEL_UNKNOWN;
	}
	return LOC_enuModeLState;
}

Actuator_tenuModeRState Actuator_enuGetModeRStatus(void)
{
	static Actuator_tenuModeRState LOC_enuModeRState = MODER_UNKNOWN;
    uint8 u8ModeRActCurrPosi = 0u;
    u8ModeRActCurrPosi = Actuator_au8CurPos[u8ACT_MODER];
	if(s8ABS_DIFF(u8ModeRActCurrPosi ,u8MODER_VENT) <= 2)
	{
       LOC_enuModeRState = MODER_VENT;
	}
	else if(s8ABS_DIFF(u8ModeRActCurrPosi ,u8MODER_FOOT) <= 2)
	{
       LOC_enuModeRState = MODER_FOOT;
	}
	else if(s8ABS_DIFF(u8ModeRActCurrPosi ,u8MODER_DEF) <= 2)
	{
       LOC_enuModeRState = MODER_DEF;
	}
	else 
	{
       LOC_enuModeRState = MODER_UNKNOWN;
	}
	return LOC_enuModeRState;
}

	   
/* the return value is equal to practical voltage *10  */
uint8 Actuator_u8GetRecFeedbackVolt(uint8 u8ActId)
{
    uint8 au8RecFbVolt[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
    uint16 au16AiRecAdcValue[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
    uint32 u32data;
    /*! Calculate Rec Feedback ADC Value */ 
    switch(u8ActId)
    {
       case u8ACT_MIXL:
	     au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MIXL_ID);
       break;
       
      case u8ACT_MIXR:
	     au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MIXR_ID);
       break;

      case u8ACT_MODEL:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MODEL_ID);
       break;

	  case u8ACT_MODER:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MODER_ID);
       break;  

	  case u8ACT_DEFROST:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8DEFORST_ID);
       break;
       
      case u8ACT_RECY:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8RECY_ID);
       break;
	   
      default:
      break;
    }
    /* 10*Volt = 10*ADC*5/1024*/
    u32data = (uint32)(10u*au16AiRecAdcValue[u8ActId]*5u/1024u);
    au8RecFbVolt[u8ActId] = (uint8)u32data;
    return au8RecFbVolt[u8ActId] ;

}

uint16 Actuator_u16GetCurrFbAdc(uint8 u8ActId)
{
    uint16 au16AiRecAdcValue[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
    /*! Calculate Rec Feedback ADC Value */ 
    switch(u8ActId)
    {
       case u8ACT_MIXL:
	     au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MIXL_ID);
       break;
       
      case u8ACT_MIXR:
	     au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MIXR_ID);
       break;

      case u8ACT_MODEL:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MODEL_ID);
       break;

	  case u8ACT_MODER:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8MODER_ID);
       break;  

	  case u8ACT_DEFROST:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8DEFORST_ID);
       break;
       
      case u8ACT_RECY:
         au16AiRecAdcValue[u8ActId] = Adc_u16Read(ADC_u8RECY_ID);
       break;
       
      default:
      break;
    }
    return au16AiRecAdcValue[u8ActId];
}

/*get Actuator running Failure state,DTC may use*/
Actuator_tenuFailureState Actuator_enuGetFailureState(uint8 u8ActId)
{
   uint8 au8RecFeedbackVoltage[u8ACT_NUM] = {0u,0u,0u,0u,0u,0u};
   au8RecFeedbackVoltage[u8ActId] = Actuator_u8GetRecFeedbackVolt(u8ActId);
   /*Feedback voltage <0.5v*/
   if( au8RecFeedbackVoltage[u8ActId]  < 5u )
   {
      Actuator_aenuFailureState[u8ActId] = Actuator_FeedBackShortToGNDorOPEN;
   }
   /*Feedback voltage >4.5v*/
   else if(au8RecFeedbackVoltage[u8ActId]  > 45u)
   {
      Actuator_aenuFailureState[u8ActId] = Actuator_FeedBackShortToVCC5;
   }
   else
   {
      Actuator_aenuFailureState[u8ActId] = Actuator_FeedBackNormal;
   }
   return Actuator_aenuFailureState[u8ActId];
}

/** \} */ /* end of Actuator module group */
/** \} */ /* end of Actuator Component group */
void vidAppMixMotorMng(uint8 u8MixLReq ,uint8 u8MixRReq  )
{
  u8MixRReq = 100u-u8MixRReq;
  Actuator_vidSetPosition(u8ACT_MIXL,u8MixLReq);
  Actuator_vidSetPosition(u8ACT_MIXR,u8MixRReq);
}

void vidAppModeMotorMng(uint8 u8ModeReq)
{
  /*****************code put here*****************/
  //MODEL MOTOR SET
  if(0u == IfRteApp_Get_ModeSts())
  {
    Actuator_vidSetPosition(u8ACT_MODEL,0u);
    Actuator_vidSetPosition(u8ACT_MODER,100u);
    Actuator_vidSetPosition(u8ACT_DEFROST,100u);
  }
  else if(2u == IfRteApp_Get_ModeSts())
  {
    Actuator_vidSetPosition(u8ACT_MODEL,50u);
    Actuator_vidSetPosition(u8ACT_MODER,50u);
    Actuator_vidSetPosition(u8ACT_DEFROST,100u);
  }
  else if(4u == IfRteApp_Get_ModeSts())
  {
    Actuator_vidSetPosition(u8ACT_MODEL,100u);
    Actuator_vidSetPosition(u8ACT_MODER,0u);
    Actuator_vidSetPosition(u8ACT_DEFROST,0u);
  }
  else
  {
    Actuator_vidSetPosition(u8ACT_MODEL,0u);
    Actuator_vidSetPosition(u8ACT_MODER,100u);
    Actuator_vidSetPosition(u8ACT_DEFROST,100u);
  }
}

void vidAppIntakeMotorMng(uint8 u8IntakeReq)
{

/*  if( 1u == IfRteApp_Get_IntakeSts())
  {
    Actuator_vidSetPosition(u8ACT_RECY,0u);
  }
  else
  {
    Actuator_vidSetPosition(u8ACT_RECY,100u);
  }*/
  Actuator_vidSetPosition(u8ACT_RECY,u8IntakeReq);
}
/*-------------------------------- end of file -------------------------------*/
