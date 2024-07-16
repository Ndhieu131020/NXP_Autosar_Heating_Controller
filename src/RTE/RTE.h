/*
 * RTE.h
 *
 *  Created on: July 14, 2024
 *      Author: ndhieu131020
 */

#ifndef RTE_H_
#define RTE_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "Mcal.h"

/*******************************************************************************
 * Define and typedef
 ******************************************************************************/
typedef struct {
    uint8_t Red_Color;
    uint8_t Green_Color;
    uint8_t Blue_Color;
}LedActuator_Typedef;

typedef enum
{
    No_Event,
    Read_Sensor_Event,
    Over_Threshold_Event,
    Under_Threshold_Event
}Event_Typedef;

/*******************************************************************************
 * Define function
 ******************************************************************************/

/*
 * @brief  Update the ADC value with the provided input.
 * @param  Value_Input - The sensor value to be updated.
 * @retval None
 */
void Rte_WriteSensorValue(uint8_t Value_Input);

/*
 * @brief  Retrieve the current ADC value.
 * @param  Value_Output - Pointer to where the current Sensor value will be stored.
 * @retval None
 */
void Rte_ReadSensorValue(uint8_t *Value_Output);

/*
 * @brief  Update the RGB value with the provided input.
 * @param  Value_Input: The RGB value to be updated.
 * @retval None
 */
void Rte_WriteLedActuator(LedActuator_Typedef Value_Input);

/*
 * @brief  Retrieve the current RGB value.
 * @param  Value_Output: Pointer to where the current RGB value will be stored.
 * @retval None
 */
void Rte_ReadLedActuator(LedActuator_Typedef *Value_Output);

/*
 * @brief  Update the Sensor event.
 * @param  Value_Input - The sensor event to be updated.
 * @retval None
 */
void Rte_WriteSensorEvent(volatile Event_Typedef Value_Input);

/*
 * @brief  Retrieve the Sensor event.
 * @param  Value_Output - Pointer to where the current Sensor event will be stored.
 * @retval None
 */
void Rte_ReadSensorEvent(volatile Event_Typedef *Value_Output);

/*
 * @brief  Update the over/under event.
 * @param  Value_Input
 * @retval None
 */
void Rte_WriteThresholdEvent(volatile Event_Typedef Value_Input);

/*
 * @brief  Retrieve the over/under event.
 * @param  Value_Output
 * @retval None
 */
void Rte_ReadThresholdEvent(volatile Event_Typedef *Value_Output);

#endif /* RTE_RTE_H_ */
