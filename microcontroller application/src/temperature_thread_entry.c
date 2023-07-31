/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include <temperature_thread.h>
#include "bsp_api.h"
#include "fx_api.h"
#include "hal_data.h"

#define UNUSED(x) (void)(x)
#define REFERENCE_VALUE 1620
#define REFERENCE_TEMP  26
#define SLOPE  6.25

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * function prototypes
 ***********************************************************************************************************************/
void temperature_thread_entry(void);

/***********************************************************************************************************************
 * global variables

 ***********************************************************************************************************************/


uint16_t adc_data;

float temp;

/* Thread0 entry function */
void temperature_thread_entry(void)
{

        ssp_err_t status;

        // Initialize ADC Driver
        status = g_adc.p_api->open(g_adc.p_ctrl, g_adc.p_cfg);

        if(status != SSP_SUCCESS)
        {
            while (1);
        }

        //Configure ADC Channel
        status =  g_adc.p_api->scanCfg(g_adc.p_ctrl, g_adc.p_channel_cfg);

        if(status != SSP_SUCCESS)
        {
            while (1);
        }

        while (1)
        {

            //Start the ADC scan

            status = g_adc.p_api->scanStart(g_adc.p_ctrl);

            if(status == SSP_SUCCESS)
            {
            //Check scan status
            status = g_adc.p_api->scanStatusGet(g_adc.p_ctrl);
            }

            if(SSP_SUCCESS == status)
            {

                // Stop the scan
                g_adc.p_api->scanStop(g_adc.p_ctrl);

            }


            //Read the result
            g_adc.p_api->read(g_adc.p_ctrl, ADC_REG_TEMPERATURE, &adc_data);




            //Convert ADC value to temperature using linear interpolation
            //Equation: temp = (adc measured voltage - reference voltage)/slope + reference temp at reference voltage

            temp = (((float) adc_data - (float) REFERENCE_VALUE) / (float) SLOPE ) + (float) REFERENCE_TEMP;




            /* Sleep for 1000msec   */
            tx_thread_sleep(10);

            /* Set event flag 0 to wake up light thread.  */
            status =  tx_event_flags_set(&g_event_flags_0, 0x1, TX_OR);

            /* Check status.  */
            if (status != TX_SUCCESS)
            {
                 break;
            }

           }

        //Close the channel
        g_adc.p_api->close(g_adc.p_ctrl);

}

