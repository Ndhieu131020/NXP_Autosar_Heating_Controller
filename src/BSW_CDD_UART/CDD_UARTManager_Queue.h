/*
 * UARTController_Queue.h
 *
 *  Created on: Jul 8, 2024
 *      Author: ndhie
 */

#ifndef CDD_UARTMANAGER_QUEUE_H_
#define CDD_UARTMANAGER_QUEUE_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include <stdint.h>

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define QUEUE_MAX_ELEMENT    1000

typedef struct
{
    int16_t Front;
    int16_t Rear;
    int16_t Size;
    uint8_t Data_Request[QUEUE_MAX_ELEMENT];
}QUEUE_Typedef;

typedef enum
{
    Queue_Full,
    Queue_Empty,
    Available
}QUEUE_Status;

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Initialize queue with default value
  * @param  None
  * @retval None
  */
void UARTController_QueueInit(void);

/**
  * @brief  Checking Queue is full
  * @param  None
  * @retval Queue status
  */
QUEUE_Status UARTController_QueueisFull(void);

/**
  * @brief  Checking Queue is empty
  * @param  None
  * @retval Queue status
  */
QUEUE_Status UARTController_QueueisEmpty(void);

/**
  * @brief  Push a line of record to the queue
  * @param  Data in
  * @retval None
  */
void UARTController_Enqueue(uint8_t data);

/**
  * @brief  Get front data and pop it to the queue
  * @param  None
  * @retval Data out
  */
uint8_t UARTController_Dequeue(void);

#endif /* UARTCONTROLLER_QUEUE_H_ */
