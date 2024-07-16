/*
 * SWC_TaskManager.h
 *
 *  Created on: Jul 4, 2024
 *      Author: ndhie
 */

#ifndef SWC_TASKMANAGER_H_
#define SWC_TASKMANAGER_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include <stdint.h>
#include "RTE.h"
#include "SWC_Color_Controller.h"
#include "SWC_Override_Color.h"
#include "SWC_SensorPotentiometer.h"
#include "CDD_UARTManager.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
typedef void (*Task_Function)(void);

typedef enum
{
    TASK_IDLE,
    TASK_ACTIVE,
    TASK_END
}Task_Status;

typedef struct
{
    Task_Status Status;
    Task_Function Func_Ptr;
}Task_TypedefStructure;

#define MAX_TASKS  5

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Create task function
  * @param  ID
  * @param  State
  * @param  Task: pointer to task function
  * @retval None
  */
void Task_Create(uint8_t ID, Task_Status State, Task_Function Task);

/**
  * @brief  Active task function
  * @param  ID
  * @retval None
  */
void Run_Task(uint8_t ID);

/**
  * @brief  Suspend task function
  * @param  ID
  * @retval None
  */
void Active_Task(uint8_t ID);

/**
  * @brief  Run task function
  * @param  ID
  * @retval None
  */
void End_Task(uint8_t ID);

/**
  * @brief  Initialize Tasks that is declared in SWC
  * @param  None
  * @retval None
  */
void Task_Init(void);

/**
  * @brief  Run & Schedule tasks
  * @param  None
  * @retval None
  */
void Task_Schedule(void);

#endif /* SWC_TASKMANAGER_H_ */
