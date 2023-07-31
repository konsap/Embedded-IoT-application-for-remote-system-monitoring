/* generated thread header file - do not edit */
#ifndef LIGHT_THREAD_H_
#define LIGHT_THREAD_H_
#include "bsp_api.h"
#include "tx_api.h"
#include "hal_data.h"
#ifdef __cplusplus
extern "C" void light_thread_entry(void);
#else
extern void light_thread_entry(void);
#endif
#include "r_adc.h"
#include "r_adc_api.h"
#ifdef __cplusplus
extern "C"
{
#endif
/** ADC on ADC Instance. */
extern const adc_instance_t g_adc0;
#ifndef NULL
void NULL(adc_callback_args_t *p_args);
#endif
extern TX_EVENT_FLAGS_GROUP g_event_flags_1;
#ifdef __cplusplus
} /* extern "C" */
#endif
#endif /* LIGHT_THREAD_H_ */
