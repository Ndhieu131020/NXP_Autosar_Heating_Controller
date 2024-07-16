/*
 * UARTController.c
 *
 *  Created on: July 8, 2024
 *      Author: ndhieu131020
 */

#include "CDD_UARTManager.h"
/*******************************************************************************
 * Definition
 ******************************************************************************/

/*******************************************************************************
 * Prototypes
 ******************************************************************************/
void Send_to_Terminal(void);

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* Request flag */
static volatile uint8_t Lock_Request_Status = UNLOCKED;

/* Sending line complete flag */
static volatile uint8_t Lock_Sending_Status = UNLOCKED;

/* ID of message that contains received data */
static uint8_t IDmsg = 0u;

/* Character index */
static uint8_t Send_index = 0u;

/* Message container */
static uint8_t Message[6][25] = {0};

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
  * @brief  Initialize and start UART service
  * @param  None
  * @retval None
  */
void CDD_UART_Start_Service(void)

{
    LPUART_InitTypedef LPUART_InitStructure;

    /* Structure parameter */
    LPUART_InitStructure.LPUART_Baudrate  = 115200;
    LPUART_InitStructure.LPUART_DataBits  = LPUART_DataBits_8b;
    LPUART_InitStructure.LPUART_Parity    = LPUART_Parity_None;
    LPUART_InitStructure.LPUART_StopBits  = LPUART_StopBits_1;
    LPUART_InitStructure.LPUART_Direction = LPUART_LSB_First;

    /* Initialize LUART1 */
    HAL_LPUART_Init(IP_LPUART1, &LPUART_InitStructure);
    HAL_LPUART_ITInit(IP_LPUART1, LPUART_IT_T, ENABLE);

    /* Initialize Queue */
    UARTController_QueueInit();

    /* Callback to ISR */
    UART_IRQ_HandlerCallback(Send_to_Terminal);
}

/**
  * @brief  Stop UART service
  * @param  None
  * @retval None
  */
void CDD_UART_Stop_Service(void)
{
    HAL_LPUART_DisableTransmit(IP_LPUART1);
    Platform_SetIrq(LPUART1_RxTx_IRQn, FALSE);
}

/**
  * @brief  Send request function
  * @param  None
  * @retval Request Status
  */
Request_status CDD_UART_Request(void)
{
    __asm("CPSID i"); /* Disable all interrupt */

    Request_status retVal = Request_Discard;

    if(UARTController_QueueisFull() != Queue_Full && Lock_Request_Status == UNLOCKED)
    {
            Lock_Request_Status = LOCKED;
            retVal = Request_Accepted;
    }

    __asm("CPSIE i"); /* Enable all interrupt */

    return retVal;
}

/**
  * @brief  Send message function
  * @param  ID: ID of message
  * @retval None
  */
void CDD_UART_SendLog(uint8_t ID)
{
    if(Lock_Request_Status == LOCKED)
    {
        UARTController_Enqueue(ID);
        Lock_Request_Status = UNLOCKED;
    }
    Platform_SetIrq(LPUART1_RxTx_IRQn, TRUE);
}

/**
  * @brief  Send message to terminal function
  * @param  None
  * @retval None
  */
void Send_to_Terminal(void)
{
    if(UARTController_QueueisEmpty() != Queue_Empty)
        {
            if(Lock_Sending_Status == UNLOCKED)
            {
                IDmsg = UARTController_Dequeue();
            }
            Lock_Sending_Status = LOCKED;

            HAL_LPUART_SendChar(IP_LPUART1, Message[IDmsg][Send_index]);

            Send_index++;

            if(Message[IDmsg][Send_index] == '\0')
            {
                Lock_Sending_Status = UNLOCKED;
                Send_index = 0u;
            }
        }
        else
        {
            Platform_SetIrq(LPUART1_RxTx_IRQn, FALSE);
        }
}

/**
  * @brief  Push data that registed to Message array
  * @param  ID: Line contain log
  * @param  *arr: array in
  * @param  Size: Size of array in
  * @retval None
  */
void CDD_UART_RegisterLog(uint8_t ID, uint8_t *arr, uint8_t Size)
{
    uint8_t log_idx = 0u;

    for(log_idx = 0; log_idx < Size; log_idx++)
    {
        Message[ID][log_idx] = arr[log_idx];
    }
}
