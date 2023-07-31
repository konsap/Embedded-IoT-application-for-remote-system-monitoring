/* generated thread header file - do not edit */
#ifndef HTTP_SERVER_THREAD_H_
#define HTTP_SERVER_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void http_server_thread_entry(void);
#else
extern void http_server_thread_entry(void);
#endif
#include "nx_http_server.h"
#ifdef __cplusplus
extern "C"
{
#endif
extern NX_HTTP_SERVER g_http_server0;
#if !defined(authentication_check)
UINT authentication_check(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, CHAR **name, CHAR **password,
        CHAR **realm);
#endif
#if !defined(request_notify)
UINT request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr);
#endif
void g_http_server0_err_callback(void *p_instance, void *p_data);
void http_server_init0(void);
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* HTTP_SERVER_THREAD_H_ */
