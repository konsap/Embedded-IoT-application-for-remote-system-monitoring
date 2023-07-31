#include   "common_data.h"
#include   "nx_api.h"
#include   "demo_nx_http_htmlstrings.h"
#include   "nx_http_server.h"
#include   "http_server_thread.h"

extern UINT _nx_http_server_number_convert(UINT number, CHAR *string);



/* Define the variables used in the application...  */

extern float                     temp;
extern uint16_t                  light_value;
extern uint8_t                   humidity;

int led_1_level;
int led_2_level;


UINT    authentication_check(struct NX_HTTP_SERVER_STRUCT *server_ptr, UINT request_type, CHAR *resource, CHAR **name, CHAR **password, CHAR **realm)
{
      SSP_PARAMETER_NOT_USED(resource);
      SSP_PARAMETER_NOT_USED(request_type);
      SSP_PARAMETER_NOT_USED(server_ptr);
#if 0
      *name =  "name5";
      *password = "password6";
      *realm =  "test.htm";
      return(NX_HTTP_BASIC_AUTHENTICATE);
#else
      SSP_PARAMETER_NOT_USED(name);
      SSP_PARAMETER_NOT_USED(password);
      SSP_PARAMETER_NOT_USED(realm);
      return(NX_SUCCESS);
#endif
}

UINT    request_notify(NX_HTTP_SERVER *server_ptr, UINT request_type, CHAR *resource, NX_PACKET *packet_ptr)
{
CHAR    string[30];
UINT    status=0;
UINT    error=0;
NX_PACKET *resp_packet_ptr;
  
    SSP_PARAMETER_NOT_USED(request_type);
    SSP_PARAMETER_NOT_USED(packet_ptr);



    /* return requested resource or query */
    if(strcmp((const char*)resource,(const char*)"/temp")==0)
    {

        /* send http response */

        /* obtain a packet to be sent to the client */

         status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                     &resp_packet_ptr,
                                     NX_TCP_PACKET,
                                     NX_WAIT_FOREVER);

        /* htmlwrite(p,s)  (nx_packet_data_append(p,s,strlen(s), server_ptr-> nx_http_server_packet_pool_ptr,NX_WAIT_FOREVER))*/

        status += htmlwrite(resp_packet_ptr, htmlresponse);

        status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


        /* send data */

        status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                     &resp_packet_ptr,
                                     NX_TCP_PACKET,
                                     NX_WAIT_FOREVER);


        _nx_http_server_number_convert(temp, string);
        status += htmlwrite(resp_packet_ptr, string);

        status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);

        if(status)
          error++;

        return(NX_HTTP_CALLBACK_COMPLETED);
    }

    if(strcmp((const char*)resource,(const char*)"/light")==0)
    {

        /* send http response */
        status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                                     &resp_packet_ptr,
                                                     NX_TCP_PACKET,
                                                     NX_WAIT_FOREVER);

        status += htmlwrite(resp_packet_ptr, htmlresponse);

        status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


        /* send data */
        status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                             &resp_packet_ptr,
                                             NX_TCP_PACKET,
                                             NX_WAIT_FOREVER);


        _nx_http_server_number_convert(light_value, string);
        status += htmlwrite(resp_packet_ptr, string);

        status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


        if(status)
        {
            error++;
        }

        return(NX_HTTP_CALLBACK_COMPLETED);

    }


    if(strcmp((const char*)resource,(const char*)"/humidity")==0)
       {

           /* send http response */
           status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                                        &resp_packet_ptr,
                                                        NX_TCP_PACKET,
                                                        NX_WAIT_FOREVER);

           status += htmlwrite(resp_packet_ptr, htmlresponse);

           status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


           /* send data */
           status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                                &resp_packet_ptr,
                                                NX_TCP_PACKET,
                                                NX_WAIT_FOREVER);


           _nx_http_server_number_convert(humidity, string);
           status += htmlwrite(resp_packet_ptr, string);

           status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


           if(status)
           {
               error++;
           }

           return(NX_HTTP_CALLBACK_COMPLETED);
       }


    if(strcmp((const char*)resource,(const char*)"/led1")==0)
           {

               /* send http response */
               status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                                            &resp_packet_ptr,
                                                            NX_TCP_PACKET,
                                                            NX_WAIT_FOREVER);

               status += htmlwrite(resp_packet_ptr, htmlresponse);

               status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


               /* toggle led 1 */

               if (led_1_level == 0)
               {
                   led_1_level = 1;
               }
               else
               {
                   led_1_level = 0;
               }



               if(status)
               {
                   error++;
               }

               return(NX_HTTP_CALLBACK_COMPLETED);
           }



    if(strcmp((const char*)resource,(const char*)"/led2")==0)
               {

                   /* send http response */
                   status += nx_packet_allocate(server_ptr -> nx_http_server_packet_pool_ptr,
                                                                &resp_packet_ptr,
                                                                NX_TCP_PACKET,
                                                                NX_WAIT_FOREVER);

                   status += htmlwrite(resp_packet_ptr, htmlresponse);

                   status +=  nx_tcp_socket_send(&(server_ptr -> nx_http_server_socket), resp_packet_ptr, NX_HTTP_SERVER_TIMEOUT);


                   /* toggle led 2 */

                   if (led_2_level == 0)
                   {
                       led_2_level = 1;
                   }
                   else
                   {
                       led_2_level = 0;
                   }



                   if(status)
                   {
                       error++;
                   }

                   return(NX_HTTP_CALLBACK_COMPLETED);
               }
    return(NX_SUCCESS);
}
