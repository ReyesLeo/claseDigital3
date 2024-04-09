#pragma once
#include <stdint.h>
#include "class_timer.h"
class blinky
{
private:
    /* data */
    uint8_t _PIN;
    uint32_t _periodo;
    TIMER _time;
    enum datos{
    shutdown,
    toogle,
    wait
   };
   datos _st=shutdown;
public:
// clase para led_task
   void init(uint8_t pint, uint32_t periodo);
   void task();
   bool detect();
   



    
};

