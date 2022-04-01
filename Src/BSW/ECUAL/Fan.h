#ifndef Fun_H
#define Fun_H
/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/


/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/
/******************************************************************************/
/*! \Description the Fun Nums.
 *  \Range 
*******************************************************************************/
#define Fun_u8NUM                      ((uint8)2)

/******************************************************************************/
/*! \Description Upper limit of the Fun Level Nums.
 *  \Range 
*******************************************************************************/
#define Fun_u8NUM_FunLEVELS_F      (32u)




/******************************************************************************/
/*! \Description Fun Diagnois Status.
 *  \Range  
*******************************************************************************/


/******************************************************************************/
/* CONSTANTS DEFINITION                                                       */
/******************************************************************************/


/******************************************************************************/
/* MACRO FUNCTIONS                                                            */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/
typedef enum
{
   Fun_LEVEL_0 = 0u,
   Fun_LEVLE_1,
   Fun_LEVEL_2,
   Fun_LEVEL_3,
   Fun_LEVEL_4,
   Fun_LEVEL_5,
   Fun_LEVEL_6,
   Fun_LEVEL_7,
   Fun_LEVEL_8,
   Fun_LEVEL_9,
   Fun_LEVEL_10,
   Fun_LEVEL_11,
   Fun_LEVEL_12,
   Fun_LEVEL_13,
   Fun_LEVEL_14,
   Fun_LEVEL_15,
   Fun_LEVEL_16,
   Fun_LEVEL_17,
   Fun_LEVEL_18,
   Fun_LEVEL_19,
   Fun_LEVEL_20,
   Fun_LEVEL_21,
   Fun_LEVEL_22,
   Fun_LEVEL_23,
   Fun_LEVEL_24,
   Fun_LEVEL_25,
   Fun_LEVEL_26,
   Fun_LEVEL_27,
   Fun_LEVEL_28,
   Fun_LEVEL_29,
   Fun_LEVEL_30,
   Fun_LEVEL_31,
} Fun_tenuFunLevel;

typedef enum
{
   Fun1 = 0u,
   Fun2,
   
} Fun_tenuFunId;


/******************************************************************************/
/* GLOBAL FUNCTIONS DECLARATION                                               */
/******************************************************************************/
extern void   Fun_vidInit(void);
extern void Fun_vidSetContext(const uint16* pku16Context);


extern void Fun_vidSetFunDuty
(
  Fun_tenuFunId enuFunId,
  uint16 u16FunDuty
);

extern uint16 Fun_u16GetFunDuty(Fun_tenuFunId enuFunId);


extern void Fun_vidSetFunLevel
(
  Fun_tenuFunId enuFunId,
  Fun_tenuFunLevel enuFunLevel
);

extern Fun_tenuFunLevel Fun_enuGetFunLevel
(
  Fun_tenuFunId enuFunId
);

extern void Fun_vidManage();


#endif /* Fun_H */
/*-------------------------------- end of file -------------------------------*/



