/*
 * KOB_LOCK Driver
 * Author: Alchar
 */
#ifndef _KOB_LOCK_H_
#define _KOB_LOCK_H_

#include "c_types.h"
#include "os_type.h"
#include "osapi.h"


#define PIN_NAME_SENSOR PERIPHS_IO_MUX_GPIO4_U  //门锁开关传感器引脚名(D2)
#define PIN_NAME_LOCK PERIPHS_IO_MUX_MTMS_U    //门锁开关引脚名(D5)

#define PIN_ID_LOCK 14  //门锁开关引脚序号
#define PIN_ID_SENSOR 4 //门锁开关传感器引脚序号

#define PIN_FUNC_SENSOR FUNC_GPIO4  //门锁开关传感器引脚功能
#define PIN_FUNC_LOCK FUNC_GPIO14   //门锁开关引脚功能


typedef enum {
    LOCK_LOCK = 0x00,
    LOCK_OPEN = 0x01
} mlock_status;

/**
 * 门锁回调定义
 */ 
typedef void (*lock_status_change_cb)(mlock_status status);


mlock_status ICACHE_FLASH_ATTR LOCK_Init(lock_status_change_cb callback);   //初始化
void ICACHE_FLASH_ATTR LOCK_ON();   //开锁
void ICACHE_FLASH_ATTR LOCK_OFF();//保留


#endif