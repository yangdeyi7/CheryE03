/******************************************************************************/
/* PROJECT  :  M01                                                            */
/******************************************************************************/
/* !Layer           : TAB                                                     */
/*                                                                            */
/* !Component       : TAB                                                     */
/* !Description     : Provides interface for table					          */
/*                                                                            */
/* !Module          : TAB                                                     */
/* !Description     : Provides interface for table        					  */
/*                                                                            */
/* !File            : TAB.c                                                   */
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
/* $Archive::   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Se$*/
/* $Revision::   1.1      $$Author::   chunping.yan   $$Date::   Dec 18 2017 $*/
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/SWDatabase/CHJ_M01/archives/M01_CLM/04_Software/Sources/Services/TAB.c-arc  $
 * 
 *    Rev 1.1   Dec 18 2017 15:24:26   chunping.yan
 * Add signal 0x538
 * 
 *    Rev 1.1   Jun 30 2017 18:19:16   chunping.yan
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
#include "TAB.h"

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* DATA DEFINITION                                                            */
/******************************************************************************/

/******************************************************************************/
/* LOCAL FUNCTION DECLARATION                                                 */
/******************************************************************************/


/******************************************************************************/
/* LOCAL FUNCTION DEFINITION                                                  */
/******************************************************************************/


/******************************************************************************/
/* GLOBAL FUNCTION DEFINITION                                                 */
/******************************************************************************/

/******************************************************************************/
/*!Function :   LinInterpolation16                                            */
/*! \Description  X increase table     
    \return      void
    Trace_to    
*******************************************************************************/
sint16 LinInterpolation16(sint16 swInput, const TAB16 *patTable)
{
   
   /*! Lineare Interpolation Input 16 Bit signed, Output 16 Bit signed*/
  
   while (swInput > patTable->x) 
   {  
      patTable++;
   }

   if (swInput == patTable->x)  
  
   {    
      return(patTable->y);
   } 
   else
   {    
      /*~+:Lineare Interpolation*/
      patTable--;   
     return( (((patTable+1)->y - patTable->y) * (swInput - patTable->x)) / ((patTable+1)->x - patTable->x) + patTable->y );

   }
   
   
}  /* end of LinInterpolation16()  */

sint16 LinInterpolation16Dyn(sint16 swInput, const TAB16 *patTable, sint16 *ps16DynData)
{
   /*! Lineare Interpolation Input 16 Bit signed, Output 16 Bit signed*/
  
   while (swInput > patTable->x) 
   {  
      patTable++;
	  ps16DynData++;
   }

   if (swInput == patTable->x)  
  
   {    
      return (*ps16DynData);
   } 
   else
   {    
      /*~+:Lineare Interpolation*/
      patTable--; 
	  ps16DynData--;  
     return( (((*(ps16DynData+1)) - (*ps16DynData)) * (swInput - patTable->x)) / ((patTable+1)->x - patTable->x) + (*ps16DynData) );

   }	
}

sint16 LinRevInterpolation16Dyn(sint16 swInput, const TAB16 *patTable, sint16 *ps16DynData)
{
   while (swInput < patTable->x) 
   {  
      patTable++;
	  ps16DynData++;
   }

   if (swInput == patTable->x)  
  
   {    
      return (*ps16DynData);
   } 
   else
   {    
      /*~+:Lineare Interpolation*/
      patTable--; 
	  ps16DynData--;	  
     return( ( ((*ps16DynData) - (*(ps16DynData+1)) ) * ((patTable+1)->x - swInput)) / ((patTable+1)->x - patTable->x) + (*(ps16DynData+1)) );

   }	
}

/******************************************************************************/
/*!Function :   LinInterpolation16                                            */
/*! \Description  X increase table 
    \return      void
    Trace_to    
*******************************************************************************/
sint16 LinRevInterpolation16(sint16 swInput, const TAB16 *patTable)
{   
   /*! Lineare Interpolation Input 16 Bit signed, Output 16 Bit signed*/
  
   while (swInput < patTable->x) 
   {  
      patTable++;
   }

   if (swInput == patTable->x)  
  
   {    
      return(patTable->y);
   } 
   else
   {    
      /*~+:Lineare Interpolation*/
      patTable--;   
     return( ( (patTable->y - (patTable+1)->y ) * ((patTable+1)->x - swInput)) / ((patTable+1)->x - patTable->x) + (patTable+1)->y );

   }
   
   
}  /* end of LinRevInterpolation16()  */


sint16 LinInterpolationXY(sint16 s16X, sint16 s16Y, const sint16 **ps16Tab,uint8 u8Rows,uint8 u8Cols)
{

	uint8 u8Rab,u8Rcd,u8Cac,u8Cbd,i;
	sint16 s16a,s16b,s16c,s16d,s16fRab,s16fRcd,s16fCac,s16fCbd,s16feab,s16fecd,s16Tmp;
	
	/*find row*/
	for(i=1u;i<u8Rows;i++)
	{
		s16Tmp=*((sint16*)ps16Tab + u8Cols*i + 0);
		if(s16Y<=s16Tmp)
		{
			if(s16Y==s16Tmp)
			{
				u8Rab=i;
				u8Rcd=i;
			}
			else
			{
				u8Rcd=i;
				if(i>1) u8Rab=i-1;
				else u8Rab=i;
			}
			break;
		}
	}
	/*if not found*/
	if(i>=u8Rows)
	{
		u8Rab=u8Rows-1;
		u8Rcd=u8Rows-1;		
	}
	
	/*find col*/
	for(i=1u;i<u8Cols;i++)
	{
		s16Tmp=*((sint16*)ps16Tab + u8Cols*0 + i);
		if(s16X<=s16Tmp)
		{
			if(s16X==s16Tmp)
			{
				u8Cac=i;
				u8Cbd=i;
			}
			else
			{
				u8Cbd=i;
				if(i>1u) u8Cac=i-1;
				else u8Cac=i;
			}
			break;
		}
	}
	/*if not found*/
	if(i>=u8Cols)
	{
		u8Cac=u8Cols-1;
		u8Cbd=u8Cols-1;		
	}
	
	s16a=*((sint16*)ps16Tab + u8Cols*u8Rab + u8Cac);
	s16b=*((sint16*)ps16Tab + u8Cols*u8Rab + u8Cbd);
	s16c=*((sint16*)ps16Tab + u8Cols*u8Rcd + u8Cac);
	s16d=*((sint16*)ps16Tab + u8Cols*u8Rcd + u8Cbd);
	s16fCac=*((sint16*)ps16Tab + u8Cols*0 + u8Cac);
	s16fCbd=*((sint16*)ps16Tab + u8Cols*0 + u8Cbd);
	s16fRab=*((sint16*)ps16Tab + u8Cols*u8Rab + 0);
	s16fRcd=*((sint16*)ps16Tab + u8Cols*u8Rcd + 0);

	if(s16fCbd==s16fCac)
	{
		s16feab=s16a;
		s16fecd=s16c;
	}
	else
	{
		s16feab=(s16X-s16fCac)*(s16b-s16a)/(s16fCbd-s16fCac)+s16a;
		s16fecd=(s16X-s16fCac)*(s16d-s16c)/(s16fCbd-s16fCac)+s16c;
	}
	if(s16fRcd==s16fRab)
	{
		s16Tmp=	s16feab;
	}
	else
	{
		s16Tmp=(s16Y-s16fRab)*(s16fecd-s16feab)/(s16fRcd-s16fRab)+s16feab;
	}

	return s16Tmp;

}


sint16 LinInterpolationMidPos(sint16 swInput, const sint16 *pas16Data, sint16 s16Size)
{  
    sint16 s16Rtn = -1;  
    sint16 s16Left = 0;
    sint16 s16Right = s16Size - 1;
	if (s16Size > 1)
	{
		if (swInput <= pas16Data[s16Left])
		{
			s16Rtn = s16Left;
		}
		else if (swInput >= pas16Data[s16Right])
		{
			s16Rtn = s16Right;
		}
		else
		{
			while (s16Left <= s16Right)
			{
				sint16 s16Mid = (s16Left + s16Right) / 2;  
				if (pas16Data[s16Mid] < swInput)
				{
					s16Left = s16Mid + 1;     
				}
				else if (pas16Data[s16Mid] > swInput)
				{  
					if (pas16Data[s16Mid - 1] < swInput)
					{
						s16Rtn = s16Mid - 1;
						break;
					}
					else
					{
						s16Right = s16Mid - 1;  
					}
				}
				else
				{  
					s16Rtn = s16Mid;  
					break;  
				}

			}
		}
	}
    return s16Rtn;  
}  

sint16 LinRevInterpolationMidPos(sint16 swInput, const sint16 *pas16Data, sint16 s16Size)
{  
    sint16 s16Rtn = -1;  
    sint16 s16Left = 0;
    sint16 s16Right = s16Size - 1;
	if (s16Size > 1)
	{
		if (swInput >= pas16Data[s16Left])
		{
			s16Rtn = s16Left;
		}
		else if (swInput <= pas16Data[s16Right])
		{
			s16Rtn = s16Right;
		}
		else
		{
			while (s16Left <= s16Right)
			{
				sint16 s16Mid = (s16Left + s16Right) / 2;  
				if (pas16Data[s16Mid] > swInput)
				{
					if (pas16Data[s16Mid + 1] < swInput)
					{
						s16Rtn = s16Mid;
						break;
					}
					else
					{
						s16Left = s16Mid + 1;  
					}
				}
				else if (pas16Data[s16Mid] < swInput)
				{  
					s16Right = s16Mid - 1;  
				}
				else
				{  
					s16Rtn = s16Mid;  
					break;  
				}

			}
		}
	}
    return s16Rtn;  
} 


sint16 LinInterpolationMidTab(sint16 swInput, const TAB16 *patTable, sint16 s16Size)
{  
    sint16 s16Rtn = 0;  
    sint16 s16Left = 0;
    sint16 s16Right = s16Size - 1;
	if (s16Size > 1)
	{
		if (swInput <= patTable[s16Left].x)
		{
			s16Rtn = patTable[s16Left].y;
		}
		else if (swInput >= patTable[s16Right].x)
		{
			s16Rtn = patTable[s16Right].y;
		}
		else
		{
			while (s16Left <= s16Right)
			{
				sint16 s16Mid = (s16Left + s16Right) / 2;  
				if (patTable[s16Mid].x < swInput)
				{
					s16Left = s16Mid + 1;     
				}
				else if (patTable[s16Mid].x > swInput)
				{  
					if (patTable[s16Mid - 1].x < swInput)
					{
						/* s16Rtn = s16Mid - 1; */
						s16Rtn = 
							((patTable[s16Mid].y - patTable[s16Mid - 1].y) * (swInput - patTable[s16Mid - 1].x)) / (patTable[s16Mid].x - patTable[s16Mid - 1].x) + patTable[s16Mid - 1].y;
						break;
					}
					else
					{
						s16Right = s16Mid - 1;  
					}
				}
				else
				{  
					s16Rtn = patTable[s16Mid].y;  
					break;  
				}

			}
		}
	}

    return s16Rtn;  
}  

sint16 LinRevInterpolationMidTab(sint16 swInput, const TAB16 *patTable, sint16 s16Size)
{  
    sint16 s16Rtn = 0;  
    sint16 s16Left = 0;
    sint16 s16Right = s16Size - 1;
	if (s16Size > 1)
	{
		if (swInput >= patTable[s16Left].x)
		{
			s16Rtn = patTable[s16Left].y;
		}
		else if (swInput <= patTable[s16Right].x)
		{
			s16Rtn = patTable[s16Right].y;
		}
		else
		{
			while (s16Left <= s16Right)
			{
				sint16 s16Mid = (s16Left + s16Right) / 2;  
				if (patTable[s16Mid].x > swInput)
				{
					if (patTable[s16Mid + 1].x < swInput)
					{
						s16Rtn = 
							((patTable[s16Mid].y - patTable[s16Mid + 1].y) * (patTable[s16Mid + 1].x - swInput)) / (patTable[s16Mid + 1].x - patTable[s16Mid].x) + patTable[s16Mid + 1].y;
						break;
					}
					else
					{
						s16Left = s16Mid + 1;  
					}
				}
				else if (patTable[s16Mid].x < swInput)
				{  
					s16Right = s16Mid - 1;  
				}
				else
				{  
					s16Rtn = patTable[s16Mid].y;  
					break;  
				}

			}
		}
	}
    return s16Rtn;  
} 
/*-------------------------------- end of file -------------------------------*/








