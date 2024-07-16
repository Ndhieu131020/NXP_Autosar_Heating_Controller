 /*
 * Application.c
 *
 *  Created on: July 1, 2024
 *      Author: ndhieu131020
 */
#include "CDD_UARTManager.h"
#include "SWC_TaskManager.h"
#include "SWC_SystemInit.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
volatile int exit_code = 0;

/*******************************************************************************
 * Code
 ******************************************************************************/

/*!
  \brief The main function for the project.
  \details The startup initialization sequence is the following:
 * - startup asm routine
 * - main()
*/
int main(void)
{
    App_SystemInit_CLKInit();

    App_SystemInit_NotificationInit();

    App_SystemInit_TimerInit();

    App_SystemInit_ADCInit();

    App_SystemInit_IOInit();

    Task_Init();

    /* Start debug service */
    CDD_UART_Start_Service();

    App_SystemInit_StartTimer(GptChannel_ADC, 25000);    /* 25000us */
    App_SystemInit_StartTimer(GptChannel_PWM, 100);      /* 100us */


    /*
     * *********Main Thread*************
    */
    while(1)
    {
        Task_Schedule();
    }

    return exit_code;
}

