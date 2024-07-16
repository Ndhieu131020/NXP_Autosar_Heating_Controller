/*
 * RTE.c
 *
 *  Created on: July 14, 2024
 *      Author: ndhieu131020
 */

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "RTE.h"

/*******************************************************************************
 * Variable
 ******************************************************************************/
/* Percent of potentiometer */
static uint8_t Sensor_Value  = 0u;

/* Value of actuator led */
static LedActuator_Typedef LedActuator_Value;

/* Event */
static volatile Event_Typedef Sensor_Event    = No_Event;
static volatile Event_Typedef Threshold_Event = No_Event;

/*******************************************************************************
 * Define function
 ******************************************************************************/

/*
 * @brief  Update the ADC value with the provided input.
 * @param  Value_Input - The sensor value to be updated.
 * @retval None
 */
void Rte_WriteSensorValue(uint8_t Value_Input)
{
    Sensor_Value = Value_Input;
}

/*
 * @brief  Retrieve the current ADC value.
 * @param  Value_Output - Pointer to where the current Sensor value will be stored.
 * @retval None
 */
void Rte_ReadSensorValue(uint8_t *Value_Output)
{
    (*Value_Output) = Sensor_Value;
}

/*
 * @brief  Update the RGB value with the provided input.
 * @param  Value_Input: The RGB value to be updated.
 * @retval None
 */
void Rte_WriteLedActuator(LedActuator_Typedef Value_Input)
{
    LedActuator_Value = Value_Input;
}

/*
 * @brief  Retrieve the current RGB value.
 * @param  Value_Output: Pointer to where the current RGB value will be stored.
 * @retval None
 */
void Rte_ReadLedActuator(LedActuator_Typedef *Value_Output)
{
    (*Value_Output) = LedActuator_Value;
}

/*
 * @brief  Update the Sensor event.
 * @param  Value_Input - The sensor event to be updated.
 * @retval None
 */
void Rte_WriteSensorEvent(volatile Event_Typedef Value_Input)
{
    Sensor_Event = Value_Input;
}

/*
 * @brief  Retrieve the Sensor event.
 * @param  Value_Output - Pointer to where the current Sensor event will be stored.
 * @retval None
 */
void Rte_ReadSensorEvent(volatile Event_Typedef *Value_Output)
{
    (*Value_Output) = Sensor_Event;
}

/*
 * @brief  Update the over/under event.
 * @param  Value_Input
 * @retval None
 */
void Rte_WriteThresholdEvent(volatile Event_Typedef Value_Input)
{
    Threshold_Event = Value_Input;
}

/*
 * @brief  Retrieve the over/under event.
 * @param  Value_Output
 * @retval None
 */
void Rte_ReadThresholdEvent(volatile Event_Typedef *Value_Output)
{
    (*Value_Output) = Threshold_Event;
}
