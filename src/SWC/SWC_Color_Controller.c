/*
 * SWC_DisplayLed.c
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#include "SWC_Color_Controller.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static uint8_t Sensor_Value = 0u;

static LedActuator_Typedef  Color_Value;
/*******************************************************************************
 * Code
 ******************************************************************************/

/**
  * @brief  Set Green led brightness function
  * @param  Period: Color value
  * @retval None
  */
void Task_Color_Controller(void)
{
    if(CDD_UART_Request() == Request_Accepted)
    {
        CDD_UART_SendLog(CONTROL_LOG);
    }

    Rte_ReadSensorValue(&Sensor_Value);

    Color_Value.Blue_Color = 0u;
    Color_Value.Green_Color = Sensor_Value;
    Color_Value.Red_Color = 0u;

    Rte_WriteLedActuator(Color_Value);
}
