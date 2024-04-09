#pragma once
#include <stdint.h>
#include <Arduino.h>
class TIMER
{
private:
    /* data */
    uint32_t rese;
public:
    void reset();
    uint32_t dt();
    
   // TIMER(/* args */);
    //~TIMER();
};

/*TIMER::TIMER()
{
}

TIMER::~TIMER()
{
}
*/