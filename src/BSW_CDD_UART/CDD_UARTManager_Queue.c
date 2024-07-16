/*
 * UARTController_Queue.c
 *
 *  Created on: July 8, 2024
 *      Author: ndhieu131020
 */

#include "CDD_UARTManager_Queue.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static QUEUE_Typedef QUEUE_TypedefStructure;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
  * @brief  Initialize queue with default value
  * @param  None
  * @retval None
  */
void UARTController_QueueInit(void)
{
    int16_t index = 0u;

    QUEUE_TypedefStructure.Front = -1;
    QUEUE_TypedefStructure.Rear  = -1;
    QUEUE_TypedefStructure.Size  = QUEUE_MAX_ELEMENT;

    for (index = 0; index < QUEUE_MAX_ELEMENT; index++)
    {
        QUEUE_TypedefStructure.Data_Request[index] = 0u;
    }
}

/**
  * @brief  Checking Queue is full
  * @param  None
  * @retval Queue status
  */
QUEUE_Status UARTController_QueueisFull(void)
{
    QUEUE_Status retVal = Available;

    if((QUEUE_TypedefStructure.Front == QUEUE_TypedefStructure.Rear + 1) || (QUEUE_TypedefStructure.Front == 0 && QUEUE_TypedefStructure.Rear == QUEUE_TypedefStructure.Size -1))
    {
        retVal = Queue_Full;
    }

    return retVal;
}

/**
  * @brief  Checking Queue is empty
  * @param  None
  * @retval Queue status
  */
QUEUE_Status UARTController_QueueisEmpty(void)
{
    QUEUE_Status retVal = Available;

    if(QUEUE_TypedefStructure.Front == -1)
    {
        retVal = Queue_Empty;
    }

    return retVal;
}

/**
  * @brief  Push a line of record to the queue
  * @param  Data in
  * @retval None
  */
void UARTController_Enqueue(uint8_t data)
{
    if(UARTController_QueueisFull() != Queue_Full)
    {
        if(QUEUE_TypedefStructure.Front == -1)
        {
            QUEUE_TypedefStructure.Front = 0;
        }
    }
    QUEUE_TypedefStructure.Rear = (QUEUE_TypedefStructure.Rear + 1) % QUEUE_TypedefStructure.Size;
    QUEUE_TypedefStructure.Data_Request[QUEUE_TypedefStructure.Rear] = data;
}

/**
  * @brief  Get front data and pop it to the queue
  * @param  None
  * @retval Data out
  */
uint8_t UARTController_Dequeue(void)
{
    uint8_t retVal = 0u;

    if(UARTController_QueueisEmpty() != Queue_Empty)
    {
        retVal = QUEUE_TypedefStructure.Data_Request[QUEUE_TypedefStructure.Front];

        if(QUEUE_TypedefStructure.Front == QUEUE_TypedefStructure.Rear)
        {
            QUEUE_TypedefStructure.Front = -1;
            QUEUE_TypedefStructure.Rear = -1;
        }
        else
        {
            QUEUE_TypedefStructure.Front = (QUEUE_TypedefStructure.Front + 1) % QUEUE_TypedefStructure.Size;
        }
    }

    return retVal;
}
