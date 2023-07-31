/***********************************************************************************************************************
 * Includes
 ***********************************************************************************************************************/
#include <light_thread.h>
#include "hal_data.h"

/***********************************************************************************************************************
 * Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 * function prototypes
 ***********************************************************************************************************************/
void light_thread_entry(void);

/***********************************************************************************************************************
 * global variables

 ***********************************************************************************************************************/

uint16_t light_value = 0;

extern TX_EVENT_FLAGS_GROUP g_event_flags_0;


/* Thread5 entry function */
void light_thread_entry(void)
{
    UINT    thread_status;
    ULONG   actual_flags;

    ssp_err_t status;

    // Initialize ADC

    status = g_adc0.p_api->open(g_adc0.p_ctrl, g_adc0.p_cfg);

    if (status != SSP_SUCCESS)
    {
        while(1);
    }

    // Configure channel

    status = g_adc0.p_api->scanCfg(g_adc0.p_ctrl, g_adc0.p_channel_cfg);

    if (status != SSP_SUCCESS)
       {
           while(1);
       }




    while(1)
    {

        // Start Scan

        status = g_adc0.p_api->scanStart(g_adc0.p_ctrl);


        // Get status

        if (status == SSP_SUCCESS)
        {
            status = g_adc0.p_api->scanStatusGet(g_adc0.p_ctrl);
        }

        // Stop scan
        if (status == SSP_SUCCESS)
        {
            g_adc0.p_api->scanStop(g_adc0.p_ctrl);
        }


        // Read data

        g_adc0.p_api->read(g_adc0.p_ctrl, ADC_REG_CHANNEL_0, &light_value);



        /* Wait for event flag 0.  */
        thread_status =  tx_event_flags_get(&g_event_flags_0, 0x1, TX_OR_CLEAR,
                &actual_flags, TX_WAIT_FOREVER);


        /* Sleep for 100msec   */
        tx_thread_sleep(1);

        /* Set event flag 0 to wake up light thread.  */
        status =  tx_event_flags_set(&g_event_flags_1, 0x1, TX_OR);

        /* Check status.  */
        if ((thread_status != TX_SUCCESS) || (actual_flags != 0x1))
            break;
    }


    // Close adc
    g_adc0.p_api->close(g_adc0.p_ctrl);


}
