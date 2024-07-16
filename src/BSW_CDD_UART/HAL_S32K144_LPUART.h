/*
 * HAL_S32K144_LPUART.h
 *
 *  Created on: May 3, 2024
 *      Author: ndhieu131020
 */

#ifndef HAL_S32K144_LPUART_H_
#define HAL_S32K144_LPUART_H_

/*******************************************************************************
 * Include
 ******************************************************************************/
#include "CDD_UARTManager_Queue.h"
#include "S32K144_LPUART.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define LOCKED    0u
#define UNLOCKED  1u

typedef enum
{
    DISABLE = 0,
    ENABLE = 1
}Functional_State;

typedef struct
{
    uint16_t SBR_Val;
    uint8_t  OSR_Val;
}LPUART_BaudParam;

typedef struct
{
    uint32_t LPUART_Baudrate;
    uint8_t LPUART_DataBits;
    uint8_t LPUART_Parity;
    uint8_t LPUART_StopBits;
    uint8_t LPUART_Direction;
}LPUART_InitTypedef;

/** @defgroup LPUART_DataBits
  * @{
  */
#define LPUART_DataBits_7b   0x00u
#define LPUART_DataBits_8b   0x01u
#define LPUART_DataBits_9b   0x02u
#define LPUART_DataBits_10b  0x03u

/** @defgroup LPUART_Parity
  * @{
  */
#define LPUART_Parity_Mask  0x03u
#define LPUART_Parity_None  0x00u
#define LPUART_Parity_Even  0x02u
#define LPUART_Parity_Odd   0x03u

/** @defgroup LPUART_StopBits
  * @{
  */
#define LPUART_StopBits_1   0x00u
#define LPUART_StopBits_2   0x01u

/** @defgroup LPUART_Direction
  * @{
  */
#define LPUART_LSB_First   0x00u
#define LPUART_MSB_First   0x01u

/** @defgroup LPUART Interrupt
  * @{
  */
#define LPUART_IT_T   ((uint32_t)0x00800000u)     /* Transmit interrupt */
#define LPUART_IT_R   ((uint32_t)0x00200000u)     /* Receive interrupt */
#define LPUART_IT_OI  ((uint32_t)0x08000000u)     /* Overrun interrupt */
#define LPUART_IT_NE  ((uint32_t)0x04000000u)     /* Noise error interrupt */
#define LPUART_IT_FE  ((uint32_t)0x02000000u)     /* Framing error interrupt */
#define LPUART_IT_PE  ((uint32_t)0x01000000u)     /* Parity error interrupt */

/* IRQ function type */
typedef void (*UART_IRQ_Callback)(void);

/*******************************************************************************
 * API
 ******************************************************************************/
/**
  * @brief  Disable transmitter & receiver
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @retval None
  */
void HAL_LPUART_DisableTransmit(LPUART_Type *IP_LPUARTx);

/**
  * @brief  Initialize LPUART Peripheral
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  LPUART_InitStructure: pointer to an LPUART_InitTypedef structure that
  * contains the configuration information for the specified LPUART peripheral.
  * @retval None
  */
void HAL_LPUART_Init(LPUART_Type *IP_LPUARTx, \
                     LPUART_InitTypedef *LPUART_InitStructure);

/**
  * @brief  Enable interrupt for LPUART Peripheral
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  LPUART_IT: Interrupt type, it can be a value of @@defgroup LPUART Interrupt.
  * @retval None
  */
void HAL_LPUART_ITInit(LPUART_Type *IP_LPUARTx, \
                       uint32_t LPUART_IT, \
                       Functional_State newState);

/**
  * @brief  Send a chacacter to LPUART
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  data
  * @retval None
  */
void HAL_LPUART_SendChar(LPUART_Type *IP_LPUARTx, uint8_t data);

/**
  * @brief  Send a chacacter to LPUART
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @param  data: data string
  * @param  length: length of data
  * @retval None
  */
void HAL_LPUART_SendString(LPUART_Type *IP_LPUARTx, \
                           uint8_t *data, \
                           uint16_t length);

/**
  * @brief  Receive a chacacter from LPUART
  * @param  IP_LPUARTx: refer to @LPUART_Type
  * @retval Received data
  */
uint8_t HAL_LPUART_ReceiveChar(LPUART_Type *IP_LPUARTx);

/**
  * @brief  UART handler callback function
  * @param  fp: handler function from uper layer
  * @retval None
  */
void UART_IRQ_HandlerCallback(UART_IRQ_Callback fp);

#endif /* HAL_S32K144_LPUART_H_ */
