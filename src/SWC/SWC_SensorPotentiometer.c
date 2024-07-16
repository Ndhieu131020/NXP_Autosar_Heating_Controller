/*
 * SWC_ADCApp.c
 *
 *  Created on: July 4, 2024
 *      Author: ndhieu131020
 */
#include "SWC_SensorPotentiometer.h"

/*******************************************************************************
 * Definition
 ******************************************************************************/
#define OVER_VALUE    80u

/*******************************************************************************
 * Prototypes
 ******************************************************************************/

/*******************************************************************************
 * Variables
 ******************************************************************************/
/* ADC conversion complete flag */
static volatile uint8_t ADC_Conversion_Flag  = 0u;

static uint8_t Sensor_Value = 0u;

/* ADC conversion result buffer */
static Adc_ValueGroupType AdcReadGroupBuffer = 0u;

/*******************************************************************************
 * Code
 ******************************************************************************/

/**
  * @brief  ADC0 conversion complete interrupt handler
  * @param  None
  * @retval None
  */
void ISR_CAT2_ADC0_Notification(void)
{
    ADC_Conversion_Flag = 1u;
}

/**
  * @brief  LPIT ADC interrupt handler
  * @param  None
  * @retval None
  */
void ISR_CAT2_ReadADC_Notification(void)
{
    Rte_WriteSensorEvent(Read_Sensor_Event);
}

/**
  * @brief  Trigger ADC conversion function
  * @param  None
  * @retval None
  */
void AppSensor_ReadSensor_Trigger(void)
{
    if(CDD_UART_Request() == Request_Accepted)
    {
        CDD_UART_SendLog(TRIGG_LOG);
    }

    if(Adc_GetGroupStatus(AdcGroup_0) == ADC_IDLE)
    {
        Adc_StartGroupConversion(AdcGroup_0);
    }
}


/**
  * @brief  Read & calculate potentiometer value function
  * @param  None
  * @retval potentiometer value
  */
void AppSensor_ReadSensorValue(void)
{
    if(CDD_UART_Request() == Request_Accepted)
    {
        CDD_UART_SendLog(READ_LOG);
    }

    if(ADC_Conversion_Flag == 1u)
    {
        Adc_ReadGroup(AdcGroup_0, &AdcReadGroupBuffer);

        Sensor_Value = (AdcReadGroupBuffer * 100) / 4095;

        ADC_Conversion_Flag = 0u;
    }

    Rte_WriteSensorValue(Sensor_Value);

    if(Sensor_Value > OVER_VALUE)
    {
        Rte_WriteThresholdEvent(Over_Threshold_Event);
    }
    else
    {
        Rte_WriteThresholdEvent(Under_Threshold_Event);
    }
}
