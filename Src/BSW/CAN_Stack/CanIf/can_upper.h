#ifndef   __CAN_UPPER_H__
#define	  __CAN_UPPER_H__

#include "dbc2struct.h"
unsigned char can_write_singal_with_index(unsigned char signalIndex,float singalValue);
float can_read_singal_with_index(unsigned char signalIndex);
void dbc2struct_test();

#endif

