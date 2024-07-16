/*
 * SWC_TaskManager.c
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */

#include "SWC_TaskManager.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define READ_SENSOR_TRIGGER  0u
#define READ_SENSOR_DATA     1u
#define CONTROL_LED          2u
#define OVERRIDE_COLOR       3u

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static Task_TypedefStructure Task_Structure[MAX_TASKS];

static volatile Event_Typedef Sensor_Event    = No_Event;
static volatile Event_Typedef Threshold_Event = No_Event;

/* Task message */
static uint8_t Task0_Msg[] = {"Trigger Sensor Task\r\n"};
static uint8_t Task1_Msg[] = {"Read Sensor Task\r\n"};
static uint8_t Task2_Msg[] = {"Control Led Task\r\n"};
static uint8_t Task3_Msg[] = {"Override Color Task\r\n"};

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
  * @brief  Create task function
  * @param  ID
  * @param  State
  * @param  Task: pointer to task function
  * @retval None
  */
void Task_Create(uint8_t ID, Task_Status State, Task_Function Task)
{
    Task_Structure[ID].Status = State;
    Task_Structure[ID].Func_Ptr = Task;
}

/**
  * @brief  Active task function
  * @param  ID
  * @retval None
  */
void Active_Task(uint8_t ID)
{
    Task_Structure[ID].Status = TASK_ACTIVE;
}

/**
  * @brief  Suspend task function
  * @param  ID
  * @retval None
  */
void End_Task(uint8_t ID)
{
    Task_Structure[ID].Status = TASK_END;
}

/**
  * @brief  Run task function
  * @param  ID
  * @retval None
  */
void Run_Task(uint8_t ID)
{
    if(Task_Structure[ID].Status == TASK_ACTIVE)
    {
        ((void (*)(void))Task_Structure[ID].Func_Ptr)();
        End_Task(ID);
    }
}

/**
  * @brief  Initialize Tasks that is declared in SWC
  * @param  None
  * @retval None
  */
void Task_Init(void)
{
    Task_Create(READ_SENSOR_TRIGGER, TASK_ACTIVE, (Task_Function)AppSensor_ReadSensor_Trigger);
    Task_Create(READ_SENSOR_DATA, TASK_IDLE, (Task_Function)AppSensor_ReadSensorValue);
    Task_Create(CONTROL_LED, TASK_IDLE, (Task_Function)Task_Color_Controller);
    Task_Create(OVERRIDE_COLOR, TASK_IDLE, (Task_Function)Task_OverrideColor);

    /* Register the log that will be sent to debug console */
    CDD_UART_RegisterLog(TRIGG_LOG, Task0_Msg, 20);
    CDD_UART_RegisterLog(READ_LOG, Task1_Msg, 17);
    CDD_UART_RegisterLog(CONTROL_LOG, Task2_Msg, 17);
    CDD_UART_RegisterLog(OVERRIDE_LOG, Task3_Msg, 20);
}

/**
  * @brief  Run & Schedule tasks
  * @param  None
  * @retval None
  */
void Task_Schedule(void)
{
    Run_Task(READ_SENSOR_TRIGGER);

    Rte_ReadSensorEvent(&Sensor_Event);
    if(Sensor_Event == Read_Sensor_Event)
    {
        Rte_WriteSensorEvent(No_Event);
        Active_Task(READ_SENSOR_TRIGGER);
        Active_Task(READ_SENSOR_DATA);
    }

    Run_Task(READ_SENSOR_DATA);

    Rte_ReadThresholdEvent(&Threshold_Event);
    if(Threshold_Event == Over_Threshold_Event)
    {
        Rte_WriteThresholdEvent(No_Event);
        Active_Task(OVERRIDE_COLOR);
    }
    else if(Threshold_Event == Under_Threshold_Event)
    {
        Rte_WriteThresholdEvent(No_Event);
        Active_Task(CONTROL_LED);
    }

    Run_Task(CONTROL_LED);

    Run_Task(OVERRIDE_COLOR);
}
