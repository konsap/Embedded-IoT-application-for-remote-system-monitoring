#include "Humidity_thread.h"
#include "hal_data.h"


void Humidity_thread_entry(void);
void read_sensor_data();


//Global variables

uint8_t data[40];
uint8_t humidity = 0;

//extern TX_EVENT_FLAGS_GROUP g_event_flags_1;


///* humidity_thread entry function */
void Humidity_thread_entry(void)
{

//    UINT    thread_status;
//    ULONG   actual_flags;
//
//    while (1)
//    {
//
//        read_sensor_data();
//
//        tx_thread_sleep(120);


//
//        /* Wait for event flag 1.  */
//        thread_status =  tx_event_flags_get(&g_event_flags_1, 0x1, TX_OR_CLEAR, &actual_flags, TX_WAIT_FOREVER);
//
//        if ((thread_status != TX_SUCCESS) || (actual_flags != 0x1))
//                    break;
//    }
}


//void read_sensor_data()
//{
//    /* init */
//
//    ioport_level_t level;
//
//    g_ioport.p_api->pinCfg(IOPORT_PORT_04_PIN_00, IOPORT_CFG_PORT_DIRECTION_OUTPUT);
//
//    //g_ioport.p_api->pinCfg(IOPORT_PORT_00_PIN_09, IOPORT_CFG_PORT_DIRECTION_OUTPUT);
//
//
//
//    /* Send start signal*/
//
//    g_ioport.p_api->pinWrite(IOPORT_PORT_04_PIN_00, IOPORT_LEVEL_LOW);
//
//    R_BSP_SoftwareDelay(18, BSP_DELAY_UNITS_MILLISECONDS);
//
//    //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_08, IOPORT_LEVEL_HIGH);
//
//    g_ioport.p_api->pinDirectionSet(IOPORT_PORT_04_PIN_00, IOPORT_DIRECTION_INPUT);
//
//
//
//
//    /* Wait for response */
//
//    g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//
//    //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_09, level);
//
//
//    while (level == IOPORT_LEVEL_HIGH)
//    {
//        //WAIT UNTIL RESPONSE
//        //g_ioport.p_api->pinWrite(IOPORT_PORT_04_PIN_00, IOPORT_LEVEL_HIGH);
//        g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//    }
//
//
//    /* Wait for data */
//
//    //g_ioport.p_api->pinWrite(IOPORT_PORT_04_PIN_00, IOPORT_LEVEL_LOW);
//
//    g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//
//    while (level == IOPORT_LEVEL_LOW)
//    {
//        //WAIT UNTIL DHT PULLS LINE HIGH
//        //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_09, IOPORT_LEVEL_HIGH);
//        g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//    }
//
//
//    //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_09, IOPORT_LEVEL_LOW);
//
//    g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//
//    while (level == IOPORT_LEVEL_HIGH)
//    {
//        //WAIT UNTIL DHT PULLS LINE LOW
//        //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_09, IOPORT_LEVEL_HIGH);
//        g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//    }
//
//
//
//
//    /*Get data*/
//
//    for (int i = 0; i < 40; i++)
//    {
//
//        while (level == IOPORT_LEVEL_HIGH)
//               {
//                   //WAIT UNTIL LOW
//                   //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_09, IOPORT_LEVEL_LOW);
//                   g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//               }
//
//
//        //Wait until line is high
//
//        g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//
//
//        while (level == IOPORT_LEVEL_LOW)
//        {
//            //wait
//            //debug led
//            //g_ioport.p_api->pinWrite(IOPORT_PORT_00_PIN_09, IOPORT_LEVEL_HIGH);
//            g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//        }
//
//        R_BSP_SoftwareDelay(35, BSP_DELAY_UNITS_MICROSECONDS);
//
//        g_ioport.p_api->pinRead(IOPORT_PORT_04_PIN_00, &level);
//
//        if (level == IOPORT_LEVEL_HIGH)
//        {
//            data[i] = 1;
//        }
//        else
//        {
//            data[i] = 0;
//        }
//
//
//    }
//
//
//
//
//    /*Translate data*/
//
//    uint8_t humidity_byte = 0;
//    uint8_t temp_byte = 0;
//    uint8_t check_sum = 0;
//
//
//    //humidity
//    for (uint8_t i = 0; i < 7; i++)
//    {
//        if (data[i] == 1)
//        {
//            humidity_byte |= (uint8_t) (1<<(7-i));
//        }
//    }
//
//    //temperature
//    for (uint8_t i = 16; i < 23; i++)
//       {
//           if (data[i] == 1)
//           {
//               temp_byte |= (uint8_t) (1<<(7-i));
//           }
//       }
//
//   //checksum
//    for (uint8_t i = 32; i < 40; i++)
//          {
//              if (data[i] == 1)
//              {
//                  check_sum |= (uint8_t) (1<<i);
//              }
//          }
//
//
//    //check for data a
//
//    humidity = temp_byte;
//
//
//}
