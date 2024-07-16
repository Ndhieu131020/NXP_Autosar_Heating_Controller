/*
 * SWC_SystemInit.c
 *
 *  Created on: July 7, 2024
 *      Author: ndhieu131020
 */

#include "SWC_SystemInit.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
ISR(ISR_CAT1_LPUART1_IRQ_Handler);

static uint32_t LPIT0_Freq = 0u;
static Adc_ValueGroupType ResultBuffer = 0xFFFF;

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
  * @brief  Initialize clock function
  * @param  None
  * @retval None
  */
void App_SystemInit_CLKInit(void)
{
    Mcu_Init(&Mcu_Config);
    Mcu_InitClock(McuClockSettingConfig_0);

    while(Mcu_GetPllStatus() != MCU_PLL_LOCKED);

    Mcu_DistributePllClock();

    Mcu_SetMode(McuModeSettingConf_0);

    LPIT0_Freq = Mcu_GetClockFrequency(LPIT0_CLK);
}

/**
  * @brief  Initialize timer function
  * @param  None
  * @retval None
  */
void App_SystemInit_TimerInit(void)
{
    Gpt_Init(&Gpt_Config);
    Gpt_EnableNotification(GptChannel_ADC);
    Gpt_EnableNotification(GptChannel_PWM);
}

/**
  * @brief  Initialize adc function
  * @param  None
  * @retval None
  */
void App_SystemInit_ADCInit(void)
{
    Adc_Init(&Adc_Config);
    Adc_EnableGroupNotification(AdcGroup_0);
    Adc_SetupResultBuffer(AdcGroup_0, &ResultBuffer);
}

/**
  * @brief  Initialize IO interface function
  * @param  None
  * @retval None
  */
void App_SystemInit_IOInit(void)
{
    Port_Init(NULL_PTR);
}

/**
  * @brief  Initialize interrupt function
  * @param  None
  * @retval None
  */
void App_SystemInit_NotificationInit(void)
{
    Platform_Init(NULL_PTR);
    Platform_InstallIrqHandler(LPUART1_RxTx_IRQn, ISR_CAT1_LPUART1_IRQ_Handler, NULL_PTR);

}

/**
  * @brief  Start timer counter function
  * @param  channel: Channel of timer
  * @param  Time_us: Frequency (microsecond)
  * @retval None
  */
void App_SystemInit_StartTimer(Gpt_ChannelType channel, uint16_t Time_us)
{
    int16_t us_Ticks = 0;

    us_Ticks = LPIT0_Freq / 1000000;

    Gpt_StartTimer(channel, Time_us*us_Ticks);
}
