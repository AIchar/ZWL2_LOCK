/*
 * KOB_LOCK Driver
 * Author: Alchar
 */
#include "driver/kob_lock.h"
#include "eagle_soc.h"
#include "gpio.h"

//#define LOCK_DEBUG_ON

#if defined(LOCK_DEBUG_ON)
#define LOG( format, ... ) os_printf( format, ## __VA_ARGS__ )
#else
#define LOG( format, ... )
#endif


static os_timer_t timer_lock_status_check;
static u8 lock_status = NULL;

lock_status_change_cb status_change_cb = NULL;



void ICACHE_FLASH_ATTR LOCK_CHECK(){
    u8 tmp_status;
    tmp_status = GPIO_INPUT_GET(GPIO_ID_PIN(PIN_ID_SENSOR));
    LOG("kob_lock.LOCK_CHECK: GET LOCK STATUS:%d",tmp_status);
    if (tmp_status != lock_status)
    {
        LOG("kob_lock.LOCK_CHECK: STATUS CHANGE");
        lock_status = tmp_status;
        if (status_change_cb != NULL)
        {
            status_change_cb(lock_status);
        }
        
    }          
}


/**
 * 初始化
 */
mlock_status ICACHE_FLASH_ATTR LOCK_Init(lock_status_change_cb callback)
{
    //初始化传感器IO
    PIN_FUNC_SELECT(PIN_NAME_SENSOR,PIN_FUNC_SENSOR);
    PIN_PULLUP_EN(PIN_NAME_SENSOR);

    //初始化开关IO
    PIN_FUNC_SELECT(PIN_NAME_LOCK,PIN_FUNC_LOCK);

    if (callback != NULL)
    {
        status_change_cb = callback;
    }
    

    lock_status = GPIO_INPUT_GET(GPIO_ID_PIN(PIN_ID_SENSOR));
    os_timer_disarm(&timer_lock_status_check);
	os_timer_setfn(&timer_lock_status_check,(os_timer_func_t *)LOCK_CHECK,NULL);
    os_timer_arm(&timer_lock_status_check,40,1);

    return lock_status;

}


/**
 * 开锁
 */
void ICACHE_FLASH_ATTR LOCK_ON(){
    LOG("kob_lock.LOCK_ON: LOCK OPEN");
    GPIO_OUTPUT_SET(GPIO_ID_PIN(PIN_ID_LOCK),1);
    os_delay_us(500000);
    GPIO_OUTPUT_SET(GPIO_ID_PIN(PIN_ID_LOCK),0);
}



