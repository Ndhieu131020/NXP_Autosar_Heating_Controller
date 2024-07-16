/*
 * SWC_ADCApp.h
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#ifndef SWC_SENSORPOTENTIOMETER_H_
#define SWC_SENSORPOTENTIOMETER_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "Adc.h"
#include "CDD_UARTManager.h"
#include "RTE.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define TRIGG_LOG     0U
#define READ_LOG      1U

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Trigger ADC conversion function
  * @param  None
  * @retval None
  */
void AppSensor_ReadSensor_Trigger(void);

/**
  * @brief  Read & calculate potentiometer value function
  * @param  None
  * @retval potentiometer value
  */
void AppSensor_ReadSensorValue(void);

#endif /* SWC_SENSORPOTENTIOMETER_H_ */
