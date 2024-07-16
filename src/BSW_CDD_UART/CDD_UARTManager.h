/*
 * UARTController.h
 *
 *  Created on: July 8, 2024
 *      Author: ndhieu131020
 */

#ifndef CDD_UARTMANAGER_H_
#define CDD_UARTMANAGER_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "CDD_UARTManager_Queue.h"
#include "HAL_S32K144_LPUART.h"
#include "Platform.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
typedef enum
{
    Request_Accepted,
    Request_Discard
}Request_status;

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Initialize and start UART service
  * @param  None
  * @retval None
  */
void CDD_UART_Start_Service(void);

/**
  * @brief  Stop UART service
  * @param  None
  * @retval None
  */
void CDD_UART_Stop_Service(void);

/**
  * @brief  Send request function
  * @param  None
  * @retval Request Status
  */
Request_status CDD_UART_Request(void);

/**
  * @brief  Send message function
  * @param  ID: ID of message
  * @retval None
  */
void CDD_UART_SendLog(uint8_t ID);

/**
  * @brief  Push data to Message array
  * @param  ID: Line contain log
  * @param  *arr: array in
  * @param  Size: Size of array in
  * @retval None
  */
void CDD_UART_RegisterLog(uint8_t ID, uint8_t *arr, uint8_t Size);

#endif /* CDD_UARTMANAGER_H_ */
