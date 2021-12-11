/*
 * Name        : main.c 
 * Author      : Taylan Yasar 
 * Version     : 1.0
 * Date        : 11.12.2021
 * Description : LED control on FreeRTOS
 */

// Standard includes.
#include <stdio.h>


// FreeRTOS includes.
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"


// Blue, Green and Red button PIN identification (Reference => RP2040 datasheet) 
//#define BLUE_PIN 20
#define GREEN_LED 19
#define RED_LED   18

// PIN Status (1=Hight, 0=Low) 
#define GPIO_ON     1
#define GPIO_OFF    0

// Green LED function
void GreenLEDTask(void *param)
{
    while(1){
    gpio_put(GREEN_LED, GPIO_ON);       // Green Led HIGH
    vTaskDelay(2000);                   // 1 second delay
    gpio_put(GREEN_LED, GPIO_OFF);      // Green Led LOW
    vTaskDelay(2000);                   // 1 second delay
    }
}

/* Red LED function 
void RedLEDTask(void *param)
{
    while(1){
    gpio_put(RED_LED, GPIO_ON);         // Red Led HIGH
    vTaskDelay(2000);                   // 2 seconds delay
    gpio_put(RED_LED, GPIO_OFF);        // Red Led HIGH
    vTaskDelay(2000);                   // 2 seconds delay
    }
}
 */

// Main function
int main() 
{
    stdio_init_all();                   // Standart init

    gpio_init(GREEN_LED);               // Green Led pin configuration         
    gpio_set_dir(GREEN_LED, GPIO_OUT);  // Green Led pin status (OUTPUT)
    /*
    gpio_init(RED_LED);                 // Red Led pin configuration  
    gpio_set_dir(RED_LED, GPIO_OUT);    // Red Led pin status (OUTPUT)
    */

    uint32_t status1 = xTaskCreate(
                    GreenLEDTask,
                    "Green LED",
                    128,
                    NULL,
                    1,                  // configMAX_PRIORITIES     4    ==> a priority from 0 to ( configMAX_PRIORITIES - 1 )
                    NULL);
    /*
    uint32_t status2 = xTaskCreate(
                     RedLEDTask,
                     "Red LED",
                     128,
                     NULL,
                     1,                 // configMAX_PRIORITIES     4    ==> a priority from 0 to ( configMAX_PRIORITIES - 1 )
                     NULL);
    */

    vTaskStartScheduler();              //  Starts the RTOS scheduler. After calling the RTOS kernel has control over which tasks are executed and when.


/* 
     BaseType_t xTaskCreate(    TaskFunction_t pvTaskCode,
                                const char * const pcName,
                                configSTACK_DEPTH_TYPE usStackDepth,
                                void *pvParameters,
                                UBaseType_t uxPriority,
                                TaskHandle_t *pxCreatedTask
                          );
*/
  

}
