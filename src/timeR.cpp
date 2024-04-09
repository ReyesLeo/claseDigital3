#include <timeR.h>
static uint32_t rese;
void Reset()
{
    rese=~millis()+1UL;
}
uint32_t cont()
{
   return rese+(uint32_t)(millis());
}