#include "class_timer.h"
void TIMER::reset()
{
    rese=~millis()+1UL;
}
uint32_t TIMER::dt()
{
    return rese+(uint32_t)(millis());
}

