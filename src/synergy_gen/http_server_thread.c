/* generated thread source file - do not edit */
#include "http_server_thread.h"

TX_THREAD http_server_thread;
void http_server_thread_create(void);
static void http_server_thread_func(ULONG thread_input);
static uint8_t http_server_thread_stack[4096] BSP_PLACE_IN_SECTION_V2(".stack.http_server_thread") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
void tx_startup_err_callback(void *p_instance, void *p_data);
void tx_startup_common_init(void);
#if defined(__ICCARM__)
#define g_http_server0_err_callback_WEAK_ATTRIBUTE
#pragma weak g_http_server0_err_callback  = g_http_server0_err_callback_internal
#elif defined(__GNUC__)
#define g_http_server0_err_callback_WEAK_ATTRIBUTE   __attribute__ ((weak, alias("g_http_server0_err_callback_internal")))
#endif
void g_http_server0_err_callback(void *p_instance, void *p_data)
g_http_server0_err_callback_WEAK_ATTRIBUTE;
NX_HTTP_SERVER g_http_server0;
uint8_t g_http_server0_stack_memory[4096] BSP_PLACE_IN_SECTION_V2(".stack.g_http_server0") BSP_ALIGN_VARIABLE_V2(BSP_STACK_ALIGNMENT);
/*******************************************************************************************************************//**
 * @brief      This is a weak example initialization error function.  It should be overridden by defining a user  function
 *             with the prototype below.
 *             - void g_http_server0_err_callback(void * p_instance, void * p_data)
 *
 * @param[in]  p_instance arguments used to identify which instance caused the error and p_data Callback arguments used to identify what error caused the callback.
 **********************************************************************************************************************/
void g_http_server0_err_callback_internal(void *p_instance, void *p_data);
void g_http_server0_err_callback_internal(void *p_instance, void *p_data)
{
    /** Suppress compiler warning for not using parameters. */
    SSP_PARAMETER_NOT_USED (p_instance);
    SSP_PARAMETER_NOT_USED (p_data);

    /** An error has occurred. Please check function arguments for more information. */
    BSP_CFG_HANDLE_UNRECOVERABLE_ERROR (0);
}
/*******************************************************************************************************************//**
 * @brief     Initialization function that the user can choose to have called automatically during thread entry.
 *            The user can call this function at a later time if desired using the prototype below.
 *            - void http_server_init0(void)
 **********************************************************************************************************************/
void http_server_init0(void)
{
#define SYNERGY_NOT_DEFINED
    UINT g_http_server0_err;

    /* Create HTTP Server. */
    g_http_server0_err = nx_http_server_create (&g_http_server0, "g_http_server0 HTTP Server", &g_ip0, &g_fx_media0,
                                                &g_http_server0_stack_memory[0], 4096,

#ifndef SYNERGY_NOT_DEFINED
                                                &SYNERGY_NOT_DEFINED,
#else                                                         
                                                &g_ip0_PACKET_POOL,
#endif                                                                              
                                                authentication_check,
                                                request_notify);
    if (NX_SUCCESS != g_http_server0_err)
    {
        g_http_server0_err_callback ((void *) &g_http_server0, &g_http_server0_err);
    }
#undef SYNERGY_NOT_DEFINED
}
extern bool g_ssp_common_initialized;
extern uint32_t g_ssp_common_thread_count;
extern TX_SEMAPHORE g_ssp_common_initialized_semaphore;

void http_server_thread_create(void)
{
    /* Increment count so we will know the number of ISDE created threads. */
    g_ssp_common_thread_count++;

    /* Initialize each kernel object. */

    UINT err;
    err = tx_thread_create (&http_server_thread, (CHAR *) "HTTP Server Thread", http_server_thread_func, (ULONG) NULL,
                            &http_server_thread_stack, 4096, 1, 1, 1, TX_AUTO_START);
    if (TX_SUCCESS != err)
    {
        tx_startup_err_callback (&http_server_thread, 0);
    }
}

static void http_server_thread_func(ULONG thread_input)
{
    /* Not currently using thread_input. */
    SSP_PARAMETER_NOT_USED (thread_input);

    /* Initialize common components */
    tx_startup_common_init ();

    /* Initialize each module instance. */
    /** Call initialization function if user has selected to do so. */
#if (1)
    http_server_init0 ();
#endif

    /* Enter user code for this thread. */
    http_server_thread_entry ();
}
