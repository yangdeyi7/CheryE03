/******************************************************************************/
/* PROJECT  :  XXXX                                                           */
/******************************************************************************/
/*!Layer           : LIN                                                      */
/*                                                                            */
/*!Component       : LINDRV                                                   */
/*!Description     : Contains the driver of LIN                               */
/*                                                                            */
/*!Module          : LinDrv                                                   */
/*!Description     : LinDrv                                                   */
/*                                                                            */
/*!File            : Lin_Cfg.h                                                */
/*                                                                            */
/*!Scope           : Private                                                  */
/*                                                                            */
/*!Target          : RH850F1K-S1                                              */
/*                                                                            */
/*!Vendor          : VALEO Climate Control Shashi                             */
/*                                                                            */
/* Coding language  : C                                                       */
/*                                                                            */
/* COPYRIGHT 2016 VALEO                                                       */
/* all rights reserved                                                        */
/*                                                                            */
/******************************************************************************/
/* PVCS                                                                       */
/******************************************************************************/
/* !Deviation : Inhibit MISRA rule [0288]: Dollar sign is needed by configu-  */
/*              ration management tool (PVCS)                                 */
/******************************************************************************/
/* PRQA S 0288 ++                                                             */
/* PRQA S 0292 ++                                                             */
/* $Archive::   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/A$*/
/* $Revision::   1.1     $$Author::   yunxin.liu      $$Date::   Feb 14 2017 $*/
/******************************************************************************/
/* MODIFICATION LOG :                                                         */
/******************************************************************************/
/* $Log:   V:/BRI-Database/archives/01_M8x CCU/04_Software/Sources/APP/AppESS.h-arc  $
 * 
                                                                              */
/* PRQA S 0292 --                                                             */
/* PRQA S 0288 --                                                             */

/******************************************************************************/
#ifndef LIN_CFG_RH850_H
#define LIN_CFG_RH850_H

/******************************************************************************/
/* INCLUDE FILES                                                              */
/******************************************************************************/

/******************************************************************************/
/* DEFINES                                                                    */
/******************************************************************************/

/* If use 1 channul only, the define show below:
    #define RLIN3NLOGIC0TOPHYSIC   (xu), x maybe 0 ~ 5.

   If use n channul in future, the define show below:
    #define RLIN3NLOGIC0TOPHYSIC   (xu), x maybe 0 ~ 5.
    #define RLIN3NLOGIC1TOPHYSIC   (yu), y maybe the rest 0 ~ 5.
    ...
    #define RLIN3NLOGIC(n-1)TOPHYSIC (zu), z maybe the rest 0 ~ 5.
*/

/* ******** Edit defines ******** */
#define RLIN3NCHANNELNUM               (1u)
#if (0u == RLIN3NCHANNELNUM)
    #error "RLIN3NCHANNELNUM must large than 0!"
#else
    #define RLIN3NLOGIC0TOPHYSIC                 (1u)
    #if (1u < RLIN3NCHANNELNUM)
        #define RLIN3NLOGIC1TOPHYSIC                 (1u)
        #if (2u < RLIN3NCHANNELNUM)
            #define RLIN3NLOGIC2TOPHYSIC                 (2u)
            #if (3u < RLIN3NCHANNELNUM)
                #define RLIN3NLOGIC3TOPHYSIC                 (3u)
                #if (4u < RLIN3NCHANNELNUM)
                    #define RLIN3NLOGIC4TOPHYSIC                 (4u)
                    #if (5u < RLIN3NCHANNELNUM)
                        #define RLIN3NLOGIC5TOPHYSIC                 (5u)
                        #if (6u < RLIN3NCHANNELNUM)
                            #error "RLIN3NCHANNELNUM can not large than 6!"
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
#endif

#if ((1u < RLIN3NLOGIC0TOPHYSIC) || (1u < RLIN3NLOGIC1TOPHYSIC) || \
        (1u < RLIN3NLOGIC2TOPHYSIC) || (1u < RLIN3NLOGIC3TOPHYSIC) || \
        (1u < RLIN3NLOGIC4TOPHYSIC) ||(1u < RLIN3NLOGIC5TOPHYSIC))
    #error "RLIN3n Port No. > 1 not implemented now!"
#endif

#if ((2u < RLIN3NLOGIC0TOPHYSIC) || (2u < RLIN3NLOGIC1TOPHYSIC) || \
        (2u < RLIN3NLOGIC2TOPHYSIC) || (2u < RLIN3NLOGIC3TOPHYSIC) || \
        (2u < RLIN3NLOGIC4TOPHYSIC) ||(2u < RLIN3NLOGIC5TOPHYSIC))
    #error "RLIN3n INT No. > 2 not implemented now!"
#endif

/* ******** Forbid edit following defines ******** */
/* physical channel to logic channel */
#if (0u == RLIN3NLOGIC0TOPHYSIC)
    #define RLIN3_PHY0_TO_LOGIC                  (0u)
#elif (1u == RLIN3NLOGIC0TOPHYSIC)
    #define RLIN3_PHY1_TO_LOGIC                  (0u)
#elif (2u == RLIN3NLOGIC0TOPHYSIC)
    #define RLIN3_PHY2_TO_LOGIC                  (0u)
#elif (3u == RLIN3NLOGIC0TOPHYSIC)
    #define RLIN3_PHY3_TO_LOGIC                  (0u)
#elif (4u == RLIN3NLOGIC0TOPHYSIC)
    #define RLIN3_PHY4_TO_LOGIC                  (0u)
#elif (5u == RLIN3NLOGIC0TOPHYSIC)
    #define RLIN3_PHY5_TO_LOGIC                  (0u)
#else
    #error "RLIN3n physical number can not large than 5!"
#endif

#if (1u < RLIN3NCHANNELNUM)
    #if (0u == RLIN3NLOGIC1TOPHYSIC)
        #define RLIN3_PHY0_TO_LOGIC                  (1u)
    #elif (1u == RLIN3NLOGIC1TOPHYSIC)
        #define RLIN3_PHY1_TO_LOGIC                  (1u)
    #elif (2u == RLIN3NLOGIC1TOPHYSIC)
        #define RLIN3_PHY2_TO_LOGIC                  (1u)
    #elif (3u == RLIN3NLOGIC1TOPHYSIC)
        #define RLIN3_PHY3_TO_LOGIC                  (1u)
    #elif (4u == RLIN3NLOGIC1TOPHYSIC)
        #define RLIN3_PHY4_TO_LOGIC                  (1u)
    #elif (5u == RLIN3NLOGIC1TOPHYSIC)
        #define RLIN3_PHY5_TO_LOGIC                  (1u)
    #else
        #error "RLIN3n physical number can not large than 5!"
    #endif
#endif

#if (2u < RLIN3NCHANNELNUM)
    #if (0u == RLIN3NLOGIC2TOPHYSIC)
        #define RLIN3_PHY0_TO_LOGIC                  (2u)
    #elif (1u == RLIN3NLOGIC2TOPHYSIC)
        #define RLIN3_PHY1_TO_LOGIC                  (2u)
    #elif (2u == RLIN3NLOGIC2TOPHYSIC)
        #define RLIN3_PHY2_TO_LOGIC                  (2u)
    #elif (3u == RLIN3NLOGIC2TOPHYSIC)
        #define RLIN3_PHY3_TO_LOGIC                  (2u)
    #elif (4u == RLIN3NLOGIC2TOPHYSIC)
        #define RLIN3_PHY4_TO_LOGIC                  (2u)
    #elif (5u == RLIN3NLOGIC2TOPHYSIC)
        #define RLIN3_PHY5_TO_LOGIC                  (2u)
    #else
        #error "RLIN3n physical number can not large than 5!"
    #endif
#endif

#if (3u < RLIN3NCHANNELNUM)
    #if (0u == RLIN3NLOGIC3TOPHYSIC)
        #define RLIN3_PHY0_TO_LOGIC                  (3u)
    #elif (1u == RLIN3NLOGIC3TOPHYSIC)
        #define RLIN3_PHY1_TO_LOGIC                  (3u)
    #elif (2u == RLIN3NLOGIC3TOPHYSIC)
        #define RLIN3_PHY2_TO_LOGIC                  (3u)
    #elif (3u == RLIN3NLOGIC3TOPHYSIC)
        #define RLIN3_PHY3_TO_LOGIC                  (3u)
    #elif (4u == RLIN3NLOGIC3TOPHYSIC)
        #define RLIN3_PHY4_TO_LOGIC                  (3u)
    #elif (5u == RLIN3NLOGIC3TOPHYSIC)
        #define RLIN3_PHY5_TO_LOGIC                  (3u)
    #else
        #error "RLIN3n physical number can not large than 5!"
    #endif
#endif

#if (4u < RLIN3NCHANNELNUM)
    #if (0u == RLIN3NLOGIC4TOPHYSIC)
        #define RLIN3_PHY0_TO_LOGIC                  (4u)
    #elif (1u == RLIN3NLOGIC4TOPHYSIC)
        #define RLIN3_PHY1_TO_LOGIC                  (4u)
    #elif (2u == RLIN3NLOGIC4TOPHYSIC)
        #define RLIN3_PHY2_TO_LOGIC                  (4u)
    #elif (3u == RLIN3NLOGIC4TOPHYSIC)
        #define RLIN3_PHY3_TO_LOGIC                  (4u)
    #elif (4u == RLIN3NLOGIC4TOPHYSIC)
        #define RLIN3_PHY4_TO_LOGIC                  (4u)
    #elif (5u == RLIN3NLOGIC4TOPHYSIC)
        #define RLIN3_PHY5_TO_LOGIC                  (4u)
    #else
        #error "RLIN3n physical number can not large than 5!"
    #endif
#endif

#if (5u < RLIN3NCHANNELNUM)
    #if (0u == RLIN3NLOGIC5TOPHYSIC)
        #define RLIN3_PHY0_TO_LOGIC                  (5u)
    #elif (1u == RLIN3NLOGIC5TOPHYSIC)
        #define RLIN3_PHY1_TO_LOGIC                  (5u)
    #elif (2u == RLIN3NLOGIC5TOPHYSIC)
        #define RLIN3_PHY2_TO_LOGIC                  (5u)
    #elif (3u == RLIN3NLOGIC5TOPHYSIC)
        #define RLIN3_PHY3_TO_LOGIC                  (5u)
    #elif (4u == RLIN3NLOGIC5TOPHYSIC)
        #define RLIN3_PHY4_TO_LOGIC                  (5u)
    #elif (5u == RLIN3NLOGIC5TOPHYSIC)
        #define RLIN3_PHY5_TO_LOGIC                  (5u)
    #else
        #error "RLIN3n physical number can not large than 5!"
    #endif
#endif

/******************************************************************************/
/* TYPES                                                                      */
/******************************************************************************/

/******************************************************************************/
/* FUNCTIONS DECLARATION                                                      */
/******************************************************************************/


/******************************************************************************/

#endif/* LIN_CFG_H */


