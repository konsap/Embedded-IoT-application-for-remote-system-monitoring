#include "usb_thread.h"

#define APP_USB_INS_FLAG    (0x1UL)
#define APP_USB_REM_FLAG    (0x2UL)

#define TX_WAIT_100_MSEC    10

/* USBThread entry function */
void usb_thread_entry(void)
{
ULONG flags;

    while (1)
    {
        do {
            /* Wait for USB device to be inserted but don't clear it*/
            tx_event_flags_get(&g_usb_event_flags, APP_USB_INS_FLAG, TX_OR, &flags, TX_WAIT_100_MSEC);

        } while (!flags & APP_USB_INS_FLAG);

        /* Wait for USB device to be removed but don't clear the flag*/
        tx_event_flags_get(&g_usb_event_flags, APP_USB_REM_FLAG, TX_OR, &flags, TX_WAIT_FOREVER);
    }
}

UINT ux_host_change_callback (ULONG event, UX_HOST_CLASS * class, VOID * instance)
{
UINT            status;
UX_HOST_CLASS * p_storage_class = NULL;
FX_MEDIA                    * gp_media         = FX_NULL;
UX_HOST_CLASS_STORAGE       * gp_storage       = UX_NULL;
UX_HOST_CLASS_STORAGE_MEDIA * gp_storage_media = UX_NULL;

    /* Check if there is a device insertion.  */
    if (UX_DEVICE_INSERTION == event)
    {
        /* Get the storage class.  */
        status = ux_host_stack_class_get(_ux_system_host_class_storage_name, &p_storage_class);
        if (UX_SUCCESS != status)
        {
            return (status);
        }

        /* Check if we got a storage class device.  */
        if (p_storage_class == class)
        {
            /* We only get the first media attached to the class container. */
            if (FX_NULL == gp_media)
            {
                gp_storage       = instance;
                gp_storage_media = class->ux_host_class_media;
                gp_media         = &gp_storage_media->ux_host_class_storage_media;

                status = tx_event_flags_set(&g_usb_event_flags, APP_USB_INS_FLAG, TX_OR);
                if (TX_SUCCESS != status)
                {
                    return (status);
                }
            }
        }
    }

    /* Check if some device is removed.  */
    else if (UX_DEVICE_REMOVAL == event)
    {
        /*  Check if the storage device is removed.  */
        if (instance == gp_storage)
        {
            status = tx_event_flags_set(&g_usb_event_flags, APP_USB_REM_FLAG, TX_OR);
            if (TX_SUCCESS != status)
            {
                return (status);
            }
        }
    }

    else
    {
        /* Default case, nothing to do */
    }

    return (UX_SUCCESS);
}
