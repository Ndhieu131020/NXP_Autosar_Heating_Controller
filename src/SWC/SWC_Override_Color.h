/*
 * SWC_Alert.h
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#ifndef SWC_OVERRIDE_COLOR_H_
#define SWC_OVERRIDE_COLOR_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "CDD_UARTManager.h"
#include "RTE.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define OVERRIDE_LOG  3U

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Turn on led red funtion
  * @param  None
  * @retval None
  */
void Task_OverrideColor(void);

#endif /* SWC_OVERRIDE_COLOR_H_ */
