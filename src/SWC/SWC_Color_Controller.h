/*
 * SWC_DisplayLed.h
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#ifndef SWC_COLOR_CONTROLLER_H_
#define SWC_COLOR_CONTROLLER_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "CDD_UARTManager.h"
#include "RTE.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define CONTROL_LOG   2U

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Set Green led brightness function
  * @param  Period: Color value
  * @retval None
  */
void Task_Color_Controller(void);

#endif /* SWC_COLOR_CONTROLLER_H_ */
