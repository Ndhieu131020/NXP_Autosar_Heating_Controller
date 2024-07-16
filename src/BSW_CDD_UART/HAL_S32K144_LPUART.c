/*
 * HAL_S32K144_LPUART.c
 *
 *  Created on: May 7, 2024
 *      Author: ndhieu131020
 */
#include "HAL_S32K144_LPUART.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define ABS(x)           ((x)<0 ? -(x) : (x))
#define LPUART_CLK_FREQ  40000000

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
static UART_IRQ_Callback Send_Behavior;

/*******************************************************************************
 * Code
 ******************************************************************************/
/**
  * @brief  UART handler callback function
  * @param  fp: handler function from uper layer
  * @retval None
  */
void UART_IRQ_HandlerCallback(UART_IRQ_Callback fp)
{
    Send_Behavior = fp;
}

/**
  * @brief  LPUART1 Tx interrupt handler
  * @param  None
  * @retval None
  */
void ISR_CAT1_LPUART1_IRQ_Handler(void)
{
    Send_Behavior();
}

/**
  * @brief  Calculate consistent OSR and SPR value base on baudrate
  * @param  Baudrate
  * @retval LPUART_Baudparam struct
  */
LPUART_BaudParam HAL_LPUART_CalBaudrate(uint32_t Baudrate)
{
    LPUART_BaudParam retVal;
    int8_t OSR_idx   = 0u;
    int16_t SBR      = 0u;
    int32_t Diff_min = 0xFFFFFFF;
    int32_t Diff     = 0u;

    for(OSR_idx = 7; OSR_idx < 32; OSR_idx++)
    {
        /* Calculate SBR value base on OSR index */
        SBR = (LPUART_CLK_FREQ/(Baudrate*(OSR_idx+1)));

        /* Calculate difference */
        Diff = Baudrate - (LPUART_CLK_FREQ/(SBR*(OSR_idx+1)));
        Diff = ABS(Diff);

        /* Find minimum difference */
        if(Diff < Diff_min)
        {
            Diff_min = Diff;
            retVal.OSR_Val = OSR_idx;
            retVal.SBR_Val = SBR;
        }
    }
    return retVal;
}

/**
  * @brief  Disable transmitter & receiver
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @retval None
  */
void HAL_LPUART_DisableTransmit(LPUART_Type *IP_LPUARTx)
{
    IP_LPUARTx->CTRL &= ~LPUART_CTRL_TE_MASK; /* Disable Transmitter */
    IP_LPUARTx->CTRL &= ~LPUART_CTRL_RE_MASK; /* Disable Receiver */
}

/**
  * @brief  Initialize LPUART Peripheral
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  LPUART_InitStructure: pointer to an LPUART_InitTypedef structure that
  * contains the configuration information for the specified LPUART peripheral.
  * @retval None
  */
void HAL_LPUART_Init(LPUART_Type *IP_LPUARTx, \
                     LPUART_InitTypedef *LPUART_InitStructure)
{
    LPUART_BaudParam Baudrate;

    HAL_LPUART_DisableTransmit(IP_LPUARTx);

    /* Calculate BaudRate */
    Baudrate = HAL_LPUART_CalBaudrate(LPUART_InitStructure->LPUART_Baudrate);

    IP_LPUARTx->BAUD = ((IP_LPUARTx->BAUD) & (~LPUART_BAUD_SBR_MASK)) | \
                       LPUART_BAUD_SBR(Baudrate.SBR_Val);
    IP_LPUARTx->BAUD = ((IP_LPUARTx->BAUD) & (~LPUART_BAUD_OSR_MASK)) | \
                       LPUART_BAUD_OSR(Baudrate.OSR_Val);

    /* Configure data bits */
    switch(LPUART_InitStructure->LPUART_DataBits)
    {
        case LPUART_DataBits_7b:
            IP_LPUARTx->BAUD &= ~LPUART_BAUD_M10_MASK;
            IP_LPUARTx->CTRL |= LPUART_CTRL_M7_MASK;
            break;
        case LPUART_DataBits_8b:
            IP_LPUARTx->BAUD &= ~LPUART_BAUD_M10_MASK;
            IP_LPUARTx->CTRL &= ~LPUART_CTRL_M7_MASK;
            IP_LPUARTx->CTRL &= ~LPUART_CTRL_M_MASK;
            break;
        case LPUART_DataBits_9b:
            IP_LPUARTx->BAUD &= ~LPUART_BAUD_M10_MASK;
            IP_LPUARTx->CTRL &= ~LPUART_CTRL_M7_MASK;
            IP_LPUARTx->CTRL |= LPUART_CTRL_M_MASK;
            break;
        case LPUART_DataBits_10b:
            IP_LPUARTx->CTRL &= ~LPUART_CTRL_M7_MASK;
            IP_LPUARTx->BAUD |= LPUART_BAUD_M10_MASK;
            break;
        default:
            break;
    }

    /* Configure parity bits */
    IP_LPUARTx->CTRL = ((IP_LPUARTx->CTRL) & (~LPUART_Parity_Mask)) | \
                       LPUART_InitStructure->LPUART_Parity;

    /* Configure stop bits */
    IP_LPUARTx->BAUD = ((IP_LPUARTx->BAUD) & (~LPUART_BAUD_SBNS_MASK)) | \
                       LPUART_BAUD_SBNS(LPUART_InitStructure->LPUART_StopBits);

    /* Configure direction bits */
    if(LPUART_InitStructure->LPUART_Direction == LPUART_LSB_First)
    {
        IP_LPUARTx->STAT &= ~LPUART_STAT_MSBF_MASK;
    }
    else
    {
        IP_LPUARTx->STAT |= LPUART_STAT_MSBF_MASK;
    }

    IP_LPUART1->CTRL |= LPUART_CTRL_TE_MASK | LPUART_CTRL_RE_MASK; /* Enable TR*/
}

/**
  * @brief  Enable interrupt for LPUART Peripheral
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  LPUART_IT: Interrupt type, it can be a value of @@defgroup LPUART Interrupt.
  * @retval None
  */
void HAL_LPUART_ITInit(LPUART_Type *IP_LPUARTx, \
                       uint32_t LPUART_IT, \
                       Functional_State newState)
{
    if(newState == ENABLE)
    {
        IP_LPUARTx->CTRL |= LPUART_IT;
    }
    else
    {
        IP_LPUARTx->CTRL &= ~LPUART_IT;
    }
}

/**
  * @brief  Send a chacacter to LPUART
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  data
  * @retval None
  */
void HAL_LPUART_SendChar(LPUART_Type *IP_LPUARTx, uint8_t data)
{
    if(((IP_LPUARTx->STAT & LPUART_STAT_TDRE_MASK) >> LPUART_STAT_TDRE_SHIFT) == 1u)
    {
        IP_LPUARTx->DATA = data; /* Transmit data */
    }
}

/**
  * @brief  Send a chacacter to LPUART
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  data: data string
  * @param  length: length of data
  * @retval None
  */
void HAL_LPUART_SendString(LPUART_Type *IP_LPUARTx, uint8_t *data, uint16_t length)
{
    static uint32_t index = 0u;

    if(index < length)
    {
        HAL_LPUART_SendChar(IP_LPUARTx, data[index]);
        index++;
    }
    else
    {
        index = 0u ;
    }

}

/**
  * @brief  Receive a chacacter from LPUART
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @retval Received data
  */
uint8_t HAL_LPUART_ReceiveChar(LPUART_Type *IP_LPUARTx)
{
    uint8_t retVal = 0u;

    if(((IP_LPUARTx->STAT & LPUART_STAT_RDRF_MASK) >> LPUART_STAT_RDRF_SHIFT) == 1)
    {
        retVal = IP_LPUARTx->DATA; /* Read received data */
    }

    return retVal;
}
