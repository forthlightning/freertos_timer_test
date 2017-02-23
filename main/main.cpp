#include "freertos/FreeRTOS.h"
#include "freertos/timers.h"
#include "esp_wifi.h"
#include "esp_system.h"
#include "esp_event.h"
#include "esp_event_loop.h"
#include "nvs_flash.h"
#include "driver/gpio.h"

#include "FOO.h"

#define TEST_INT 0x0001

QueueHandle_t xSDMQueue;

struct FOO FOO1( 1 );
struct FOO FOO2( 2 );

struct reading
{
    uint16_t identifier;
    long int timestamp;              // most recent time of reading
    float value;                     // value
};

// list of readings
struct sensor_config sdm_sensor_configs[] =    {{ TEST_INT,                   "voltageACOut",         7000    }};

void vTimerCallback( TimerHandle_t cb_timer )
{
    // pointer way
    // struct sdm_read_token* my_token_ptr;
    // my_token_ptr = ( struct sdm_read_token* ) pvTimerGetTimerID( cb_timer );
    // printf( "callback, meter_id: %hu, type: %hhu\n", my_token_ptr->meter_id, my_token_ptr->read_type );

    // memcpy way
    struct sdm_read_token my_token;
    memcpy( &my_token, pvTimerGetTimerID( cb_timer ), sizeof( sdm_read_token ) );
    printf( "callback, meter_id: %hu, type: %hhu\n", my_token.meter_id, my_token.read_type );
}


extern "C" void app_main(void)
{
    while( true )
    {
        vTaskDelay( 2000 / portTICK_PERIOD_MS );
    }
}

