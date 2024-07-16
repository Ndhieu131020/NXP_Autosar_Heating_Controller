/*==================================================================================================
* Project : RTD AUTOSAR 4.7
* Platform : CORTEXM
* Peripheral : Ftm_Srtc_Lptmr_LPit
* Dependencies : none
*
* Autosar Version : 4.7.0
* Autosar Revision : ASR_REL_4_7_REV_0000
* Autosar Conf.Variant :
* SW Version : 2.0.0
* Build Version : S32K1_RTD_2_0_0_D2308_ASR_REL_4_7_REV_0000_20230804
*
* Copyright 2020-2023 NXP Semiconductors
*
* NXP Confidential. This software is owned or controlled by NXP and may only be
* used strictly in accordance with the applicable license terms. By expressly
* accepting such terms or by downloading, installing, activating and/or otherwise
* using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms. If you do not agree to be
* bound by the applicable license terms, then you may not retain, install,
* activate or otherwise use the software.
==================================================================================================*/

#ifndef LPIT_GPT_IP_CFG_H
#define LPIT_GPT_IP_CFG_H

/**
*   @file           LPit_Gpt_Ip_Cfg.h
*
*   @addtogroup     lpit_ip LPit IPL
*
*   @{
*/

#ifdef __cplusplus
extern "C"{
#endif

/*==================================================================================================
*                                        INCLUDE FILES
* 1) system and project includes
* 2) needed interfaces from external units
* 3) internal and external interfaces from this unit
==================================================================================================*/
#include "LPit_Gpt_Ip_PBcfg.h"

/*==================================================================================================
*                              SOURCE FILE VERSION INFORMATION
==================================================================================================*/
#define LPIT_GPT_IP_VENDOR_ID_CFG                       43
#define LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG        4
#define LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG        7
#define LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG     0
#define LPIT_GPT_IP_SW_MAJOR_VERSION_CFG                2
#define LPIT_GPT_IP_SW_MINOR_VERSION_CFG                0
#define LPIT_GPT_IP_SW_PATCH_VERSION_CFG                0

/*==================================================================================================
*                                     FILE VERSION CHECKS
==================================================================================================*/
#if (LPIT_GPT_IP_VENDOR_ID_CFG != LPIT_GPT_IP_VENDOR_ID_PBCFG_H)
    #error "LPit_Gpt_Ip_Cfg.h and LPit_Gpt_Ip_PBcfg.h have different vendor ids"
#endif
/* Check if this header file and header file are of the same Autosar version */
#if ((LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_CFG != LPIT_GPT_IP_AR_RELEASE_MAJOR_VERSION_PBCFG_H) || \
     (LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_CFG != LPIT_GPT_IP_AR_RELEASE_MINOR_VERSION_PBCFG_H) || \
     (LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_CFG != LPIT_GPT_IP_AR_RELEASE_REVISION_VERSION_PBCFG_H) \
    )
    #error "AutoSar Version Numbers of LPit_Gpt_Ip_Cfg.h and LPit_Gpt_Ip_PBcfg.h are different"
#endif
/* Check if this header file and header file are of the same Software version */
#if ((LPIT_GPT_IP_SW_MAJOR_VERSION_CFG != LPIT_GPT_IP_SW_MAJOR_VERSION_PBCFG_H) || \
     (LPIT_GPT_IP_SW_MINOR_VERSION_CFG != LPIT_GPT_IP_SW_MINOR_VERSION_PBCFG_H) || \
     (LPIT_GPT_IP_SW_PATCH_VERSION_CFG != LPIT_GPT_IP_SW_PATCH_VERSION_PBCFG_H) \
    )
    #error "Software Version Numbers of LPit_Gpt_Ip_Cfg.h and LPit_Gpt_Ip_PBcfg.h are different"
#endif
/*==================================================================================================
*                                          CONSTANTS
==================================================================================================*/

/*==================================================================================================
*                                      DEFINES AND MACROS
==================================================================================================*/
/**
* @brief Dev error detect switch
*/
#define LPIT_GPT_IP_DEV_ERROR_DETECT     (STD_OFF)
/*==================================================================================================*/
/**
* @brief    LPIT_GPT_IP_CHAIN_MODE switch
* @details  Enable/disable API for Chain Mode.
*/
#define LPIT_GPT_IP_CHAIN_MODE     (STD_OFF)

/*================================================================================================*/
/**
* @brief    LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT switch
* @details  Enable/disable support usermode.If this parameter has been configured to TRUE the GPT driver code can be executed from both supervisor and user mode.
*/
#define LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT     (STD_OFF)

#ifndef MCAL_ENABLE_USER_MODE_SUPPORT
    #ifdef LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT
        #if (STD_ON == LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT)
            #error MCAL_ENABLE_USER_MODE_SUPPORT is not enabled. For running Gpt in user mode the MCAL_ENABLE_USER_MODE_SUPPORT needs to be defined
        #endif /* (STD_ON == LPIT_GPT_IP_ENABLE_USER_MODE_SUPPORT) */
    #endif /* ifndef MCAL_ENABLE_USER_MODE_SUPPORT */
#endif /* ifdef MCAL_ENABLE_USER_MODE_SUPPORT*/

/*================================================================================================*/
/**
* @brief    LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE switch
* @details  Enable/disable support for changing timeout value during timer running
*/
#define LPIT_GPT_IP_CHANGE_NEXT_TIMEOUT_VALUE     (STD_OFF)

/*==================================================================================================
*                                             ENUMS
==================================================================================================*/

/*==================================================================================================
*                                STRUCTURES AND OTHER TYPEDEFS
==================================================================================================*/

/*==================================================================================================
*                                GLOBAL VARIABLE DECLARATIONS
==================================================================================================*/

/*==================================================================================================
*                                    FUNCTION PROTOTYPES
==================================================================================================*/

#ifdef __cplusplus
}
#endif

/** @} */
#endif  /* LPIT_GPT_IP_CFG_H */

