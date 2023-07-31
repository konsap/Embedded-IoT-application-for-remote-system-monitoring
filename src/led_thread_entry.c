#include <led_thread.h>
#include "bsp_api.h"
#include "fx_api.h"
#include "hal_data.h"

void led_thread_entry(void);

extern int led_1_level;
extern int led_2_level;


/* led_thread entry function */
void led_thread_entry(void)
{

    /* Configure leds*/

    g_ioport.p_api->pinCfg(IOPORT_PORT_00_PIN_08, IOPORT_CFG_PORT_DIRECTION_OUTPUT);

    g_ioport.p_api->pinCfg(IOPORT_PORT_00_PIN_10, IOPORT_CFG_PORT_DIRECTION_OUTPUT);


    while (1)
    {

        g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_08, led_1_level);

        g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_10, led_2_level);

        // sleep for 100msec
        tx_thread_sleep(1);
    }
}
