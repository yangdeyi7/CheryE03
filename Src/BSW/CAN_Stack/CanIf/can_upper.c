#include "dbc2struct.h"

static void dbc2struct_signal_write(unsigned char signalIndex,unsigned int value)
{
    canFrame_t *pcanFrame;
	unsigned int   temp_value;
	unsigned char  bitlen=singalFrames[signalIndex].bitlen;
	unsigned char  currtlen=0,currentbit=0,currentpos,currentbyte,loop=0;
      
	pcanFrame       =&canFrames[singalFrames[signalIndex].canFrameIndex];
    currentbyte     =singalFrames[signalIndex].bitstart/8;
	currentpos      =singalFrames[signalIndex].bitstart-8*currentbyte;
    temp_value      =value;  

    MCU_vidDisableInterrupts();
    while(bitlen)
    {
      currentbit=(temp_value>>(bitlen-1))&0x01;
      if(singalFrames[signalIndex].byteorder==BYTEORDE_MOTOROLA)
      {//从最高位开始依次写入
        pcanFrame->canbuffer[currentbyte]&=~(1<<currentpos);
        pcanFrame->canbuffer[currentbyte]|=(currentbit<<currentpos);  
        if(currentpos==0)
        {
            currentpos=7;
            currentbyte=currentbyte+1;  
        }
        else
        {
            currentpos--;
        }
      }
      bitlen--;
    }
    MCU_vidEnableInterrupts();
      
    SEGGER_RTT_printf(0, "dbc2struct_signal_write=0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x\r\n",
                      pcanFrame->canbuffer[0],pcanFrame->canbuffer[1],
                      pcanFrame->canbuffer[2],pcanFrame->canbuffer[3],
                      pcanFrame->canbuffer[4],pcanFrame->canbuffer[5],
                      pcanFrame->canbuffer[6],pcanFrame->canbuffer[7]);
}

static unsigned int dbc2struct_signal_read(unsigned char signalIndex)
{
    canFrame_t *pcanFrame;
	unsigned int   temp_value=0;
	unsigned char  bitlen=singalFrames[signalIndex].bitlen;
	unsigned char  currtlen=0,currentpos,currentbyte,loop=0;
    unsigned int   currentbit=0;
      
	pcanFrame       =&canFrames[singalFrames[signalIndex].canFrameIndex];
    currentbyte     =singalFrames[signalIndex].bitstart/8;
	currentpos      =singalFrames[signalIndex].bitstart-8*currentbyte; 

    MCU_vidDisableInterrupts();
    while(bitlen)
    {
      if(singalFrames[signalIndex].byteorder==BYTEORDE_MOTOROLA)
      {//从最高位开始依次读取
        currentbit=(pcanFrame->canbuffer[currentbyte]>>currentpos)&0x01;//(pcanFrame->canbuffer[currentbyte]>>(bitlen-1-loop))&0x01;//pcanFrame->canbuffer[currentbyte]&=~(1<<currentpos);
        temp_value |=(currentbit<<(bitlen-1));  
        if(currentpos==0)
        {
            currentpos=7;
            currentbyte=currentbyte+1;  
        }
        else
        {
            currentpos--;
        }
      }
      bitlen--;
    }
    MCU_vidEnableInterrupts();
      
    SEGGER_RTT_printf(0, "dbc2struct_signal_read=0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x,0x%x\r\n",
                      pcanFrame->canbuffer[0],pcanFrame->canbuffer[1],
                      pcanFrame->canbuffer[2],pcanFrame->canbuffer[3],
                      pcanFrame->canbuffer[4],pcanFrame->canbuffer[5],
                      pcanFrame->canbuffer[6],pcanFrame->canbuffer[7]);
    return temp_value;
}

unsigned char can_write_singal_with_index(unsigned char signalIndex,float singalValue)
{
	float  real_value_float;
	unsigned int   temp_value;
      
    if(signalIndex>CanSingalIndex_MAX) 		return 1;//signalIndex no vaild
    if(singalFrames[signalIndex].bitlen>24)	return 2;//max support 3 byte
    
    real_value_float=(singalValue-singalFrames[signalIndex].offset)/singalFrames[signalIndex].factor;
    temp_value=(int)(real_value_float);
      
	dbc2struct_signal_write(signalIndex,temp_value);
	
	SEGGER_RTT_printf(0, "dbc2struct_write_singal_with_index=0x%x,0x%x,0x%x\r\n",signalIndex,temp_value,singalValue);
	return 0;
}

float can_read_singal_with_index(unsigned char signalIndex)
{
	float           real_value_float;
	unsigned int    temp_value;
      
    if(signalIndex>CanSingalIndex_MAX) 		return 1;//signalIndex no vaild
    if(singalFrames[signalIndex].bitlen>24)	return 2;//max support 3 byte
    
    
	temp_value=dbc2struct_signal_read(signalIndex);
	real_value_float=((float)temp_value)*singalFrames[signalIndex].factor+singalFrames[signalIndex].offset;

      
	SEGGER_RTT_printf(0, "dbc2struct_read_singal_with_index=0x%x,0x%x,0x%x\r\n",signalIndex,temp_value,(int)real_value_float);
	
    return real_value_float;
}

void dbc2struct_test()
{
    float temp1=0x123;
    float temp2=0;
      
    unsigned char index=  CanSingalIndex_SolarSenRaw;
      
    can_write_singal_with_index(index,temp1);
    temp2=can_read_singal_with_index(index);
    SEGGER_RTT_printf(0, "dbc2struct_test=0x%x,0x%x,0x%x\r\n",index,(int)temp1,(int)temp2);
       
    index=  CanSingalIndex_OnBoardTempRaw_C;
      
    can_write_singal_with_index(index,temp1);
    temp2=can_read_singal_with_index(index);
      
    SEGGER_RTT_printf(0, "dbc2struct_test=0x%x,0x%x,0x%x\r\n",index,(int)temp1,(int)temp2);
	
    while(1);
}

void can_upper_test()
{
    float temp1=0x123;
    float temp2=0;
      
    unsigned char index=  CanSingalIndex_BMS_WaterTemp_Inlet;
      

    temp2=can_read_singal_with_index(index);
    SEGGER_RTT_printf(0, "can_upper_test::t0x%x,0x%x\r\n",index,(int)temp2);
}
void canId_get_with_index()
{

}