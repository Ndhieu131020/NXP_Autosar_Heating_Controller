/*
 * App_Led_Controller.c
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#include "SWC_Actuator_LedController.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* LPIT0 CH1 counter */
static volatile uint8_t PWM_Count = 0u;

static LedActuator_Typedef  Color_Value;

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
  * @brief  LPIT0 Channel 1 interrupt handler
  * @param  None
  * @retval None
  */
void ISR_CAT1_ControlLed_Notification(void)
{
    PWM_Count++;

    if(PWM_Count >= 100)
    {
        PWM_Count = 0u;
    }

    Rte_ReadLedActuator(&Color_Value);

    if(PWM_Count < Color_Value.Red_Color)
    {
        Dio_WriteChannel(LED_RED, ON);
    }
    else
    {
        Dio_WriteChannel(LED_RED, OFF);
    }

    if(PWM_Count < Color_Value.Green_Color)
    {
        Dio_WriteChannel(LED_GREEN, ON);
    }
    else
    {
        Dio_WriteChannel(LED_GREEN, OFF);
    }

    if(PWM_Count < Color_Value.Blue_Color)
    {
        Dio_WriteChannel(LED_BLUE, ON);
    }
    else
    {
        Dio_WriteChannel(LED_BLUE, OFF);
    }
}
