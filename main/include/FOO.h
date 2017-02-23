#ifndef FOO_H
#define FOO_H

#undef write
#undef read
#include <Arduino.h>
#include <string.h>
#include "esp32-hal.h"
#include "driver/uart.h"
#include "soc/uart_struct.h"

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_system.h"

#define NUM_TIMERS 1

extern QueueHandle_t xSDMQueue;
void sdm_reader_task( void* );
void vTimerCallback( TimerHandle_t timer);

// token to indicate a sensor to read
struct sdm_read_token
{
    uint8_t meter_id;
    uint16_t read_type;
};

struct sensor_config
{
    uint16_t identifier;
    const char name[20];
    int sensor_delay;
};
extern sensor_config sdm_sensor_configs[];

struct FOO
{

	private:

        TimerHandle_t xTimers[ NUM_TIMERS ];

    public:

        FOO( int meter_id )
        {
            // begin all the timers
            for( int i = 0; i < NUM_TIMERS; i++ )
            {
                struct sdm_read_token my_token;
                my_token.meter_id = meter_id;
                my_token.read_type = sdm_sensor_configs[ i ].identifier;

                void* token_ptr = &my_token;
                // when i change id, my_token_ptr->meter_id changes!! 
                // change "-----" to "zzzzzz" and meter_id will change
                xTimers[ i ] = xTimerCreate(    "-------",                                                // text name of timer,
                                                sdm_sensor_configs[ i ].sensor_delay / portTICK_PERIOD_MS,  // timer interval
                                                pdTRUE,                                                     // reset timer?
                                                token_ptr,                                                  // timer id, in this case token object
                                                vTimerCallback );                                           // timer callback function

                // check to see if pvTimerGetTimerID( timer ) works ... it does
                struct sdm_read_token* my_token_ptr;
                my_token_ptr = ( struct sdm_read_token* ) pvTimerGetTimerID( xTimers[i] );
                printf( "constructor, meter_id: %hu, read_type: %hhu\n", my_token_ptr->meter_id, my_token_ptr->read_type );

                if( xTimers[ i ] != NULL )
                {
                    xTimerStart( xTimers[ i ], 0 );
                }
            }

            // create recipient queue for all the sensors
            xSDMQueue = xQueueCreate( 10, sizeof( sdm_read_token ) );
        }
};
#endif
