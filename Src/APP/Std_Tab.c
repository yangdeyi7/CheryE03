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
#include "Std_Tab.h"

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
sint16 LinInterpolation16(sint16 s16Input, const TAB16 *patTable)
{
    /*! Lineare Interpolation Input 16 Bit signed, Output 16 Bit signed*/
    while (s16Input > patTable->x) 
    {  
        patTable++;
    }

    if (s16Input == patTable->x)  
    {    
        return(patTable->y);
    } 
    else
    {    
        /*~+:Lineare Interpolation*/
        patTable--;   
        return( (((patTable+1u)->y - patTable->y) * (s16Input - patTable->x)) / ((patTable+1u)->x - patTable->x) + patTable->y );
    }
}

sint16 LinInterpolation16Dyn(sint16 s16Input, const TAB16 *patTable, sint16 *ps16DynData)
{
    /*! Lineare Interpolation Input 16 Bit signed, Output 16 Bit signed*/
    while (s16Input > patTable->x) 
    {  
        patTable++;
        ps16DynData++;
    }

    if (s16Input == patTable->x)  
    {    
        return (*ps16DynData);
    } 
    else
    {    
        /*~+:Lineare Interpolation*/
        patTable--; 
        ps16DynData--;  
        return( (((*(ps16DynData+1u)) - (*ps16DynData)) * (s16Input - patTable->x)) / ((patTable+1u)->x - patTable->x) + (*ps16DynData) );
    }
}

sint16 LinInterpolationXY(sint16 s16X, sint16 s16Y, const sint16 **ps16Tab,uint8 u8Rows,uint8 u8Cols)
{
    uint8 u8Rab = 0u;
    uint8 u8Rcd = 0u;
    uint8 u8Cac = 0u;
    uint8 u8Cbd = 0u;
    uint8 u8Index = 0u;
    sint16 s16a = (sint16)0;
    sint16 s16b = (sint16)0;
    sint16 s16c = (sint16)0;
    sint16 s16d = (sint16)0;
    sint16 s16fRab = (sint16)0;
    sint16 s16fRcd = (sint16)0;
    sint16 s16fCac = (sint16)0;
    sint16 s16fCbd = (sint16)0;
    sint16 s16feab = (sint16)0;
    sint16 s16fecd = (sint16)0;
    sint16 s16Tmp = (sint16)0;

    /*find row*/
    for(u8Index = 1u; u8Index<u8Rows; u8Index++)
    {
        s16Tmp = *((sint16*)ps16Tab + u8Cols*u8Index);
        if(s16Y <= s16Tmp)
        {
            if(s16Y == s16Tmp)
            {
                u8Rab = u8Index;
                u8Rcd = u8Index;
            }
            else
            {
                u8Rcd = u8Index;
                if(u8Index > 1u)
                {
                    u8Rab = u8Index - 1u;
                }
                else
                {
                    u8Rab = u8Index;
                }
            }
            break;
        }
    }
    
    /*if not found*/
    if(u8Index>=u8Rows)
    {
        u8Rab = u8Rows - 1u;
        u8Rcd = u8Rows - 1u;
    }

    /*find col*/
    for(u8Index = 1u; u8Index < u8Cols; u8Index++)
    {
        s16Tmp = *((sint16*)ps16Tab + u8Cols*0u + u8Index);
        if(s16X <= s16Tmp)
        {
            if(s16X==s16Tmp)
            {
                u8Cac = u8Index;
                u8Cbd = u8Index;
            }
            else
            {
                u8Cbd = u8Index;
                if(u8Index > 1u)
                {
                    u8Cac = u8Index - 1u;
                }
                else
                {
                    u8Cac = u8Index;
                }
            }
            break;
        }
    }
    
    /*if not found*/
    if(u8Index >= u8Cols)
    {
        u8Cac = u8Cols - 1u;
        u8Cbd = u8Cols - 1u;
    }

    s16a = *((sint16*)ps16Tab + u8Cols*u8Rab + u8Cac);
    s16b = *((sint16*)ps16Tab + u8Cols*u8Rab + u8Cbd);
    s16c = *((sint16*)ps16Tab + u8Cols*u8Rcd + u8Cac);
    s16d = *((sint16*)ps16Tab + u8Cols*u8Rcd + u8Cbd);
    s16fCac = *((sint16*)ps16Tab + u8Cols*0u + u8Cac);
    s16fCbd = *((sint16*)ps16Tab + u8Cols*0u + u8Cbd);
    s16fRab = *((sint16*)ps16Tab + u8Cols*u8Rab + 0u);
    s16fRcd = *((sint16*)ps16Tab + u8Cols*u8Rcd + 0u);

    if(s16fCbd == s16fCac)
    {
        s16feab = s16a;
        s16fecd = s16c;
    }
    else
    {
        s16feab = (sint16)((s16X-s16fCac)*(s16b-s16a)/(s16fCbd-s16fCac)+s16a);
        s16fecd = (sint16)((s16X-s16fCac)*(s16d-s16c)/(s16fCbd-s16fCac)+s16c);
    }
    
    if(s16fRcd == s16fRab)
    {
        s16Tmp = s16feab;
    }
    else
    {
        s16Tmp = (sint16)((s16Y-s16fRab)*(s16fecd-s16feab)/(s16fRcd-s16fRab)+s16feab);
    }

    return s16Tmp;
}



/*-------------------------------- end of file -------------------------------*/

