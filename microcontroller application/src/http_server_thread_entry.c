#include "http_server_thread.h"
#include "usb_thread.h"

#define APP_USB_INS_FLAG    (0x1UL)
#define APP_USB_REM_FLAG    (0x2UL)

UINT err_counter=0;;
/* HTTP Server Thread entry function */
void http_server_thread_entry(void)
{
UINT status;
ULONG flags;

    /* TODO: add your own code here */
    while (1)
    {
        status = tx_event_flags_get(&g_usb_event_flags, APP_USB_INS_FLAG, TX_AND_CLEAR, &flags, TX_WAIT_FOREVER);
        /* The reason we are updating the media pointer is, http server gets created before the USB is detected/Inserted.
         * Update the USB Media Pointer before the HTTP Server is Started
         */
        if(status)
        {
            err_counter++;
        }
        g_http_server0.nx_http_server_media_ptr = g_fx_media0_ptr;

        status = nx_http_server_start(&g_http_server0);
        if(status)
        {
             err_counter++;
        }

        status = tx_event_flags_get(&g_usb_event_flags, APP_USB_REM_FLAG, TX_AND_CLEAR, &flags, TX_WAIT_FOREVER);
        if(status)
        {
             err_counter++;
        }

        status = nx_http_server_stop(&g_http_server0);
        if(status)
        {
             err_counter++;
        }
    }
}
