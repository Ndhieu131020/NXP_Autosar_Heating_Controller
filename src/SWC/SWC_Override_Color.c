/*
 * SWC_Alert.c
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#include "SWC_Override_Color.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static LedActuator_Typedef  Color_Value;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
  * @brief  Turn on led red funtion
  * @param  None
  * @retval None
  */
void Task_OverrideColor(void)
{
    if(CDD_UART_Request() == Request_Accepted)
    {
        CDD_UART_SendLog(OVERRIDE_LOG);
    }

    Color_Value.Red_Color   = 100u;
    Color_Value.Green_Color = 0u;
    Color_Value.Blue_Color  = 0u;

    Rte_WriteLedActuator(Color_Value);
}
