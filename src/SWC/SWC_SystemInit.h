/*
 * SWC_SystemInit.h
 *
 *  Created on: July 7, 2024
 *      Author: ndhieu131020
 */

#ifndef SWC_SYSTEMINIT_H_
#define SWC_SYSTEMINIT_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "Mcal.h"
#include "Adc.h"
#include "Mcu.h"
#include "Platform.h"
#include "Gpt.h"
#include "Dio.h"
#include "Port.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define GptChannel_ADC    GptConf_GptChannelConfiguration_GptChannelConfiguration_0
#define GptChannel_PWM    GptConf_GptChannelConfiguration_GptChannelConfiguration_1

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Initialize clock function
  * @param  None
  * @retval None
  */
void App_SystemInit_CLKInit(void);

/**
  * @brief  Initialize timer function
  * @param  None
  * @retval None
  */
void App_SystemInit_TimerInit(void);

/**
  * @brief  Initialize adc function
  * @param  None
  * @retval None
  */
void App_SystemInit_ADCInit(void);

/**
  * @brief  Initialize IO interface function
  * @param  None
  * @retval None
  */
void App_SystemInit_IOInit(void);

/**
  * @brief  Initialize interrupt function
  * @param  None
  * @retval None
  */
void App_SystemInit_NotificationInit(void);

/**
  * @brief  Start timer counter function
  * @param  channel: Channel of timer
  * @param  Time_us: Frequency (microsecond)
  * @retval None
  */
void App_SystemInit_StartTimer(Gpt_ChannelType channel, uint16_t Time_us);

#endif /* SWC_SYSTEMINIT_H_ */
