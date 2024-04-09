#include "led_task.h"
#include "class_timer.h"
#include <Arduino.h>
namespace datos
{
    int _st;
    uint8_t _PIN;
    uint32_t _periodo;
    TIMER _time;
    void ini(uint8_t pin, uint32_t periodo)
    {
       pinMode(pin,OUTPUT);
       _st=1;
       _periodo=periodo;
       _PIN=pin;
    }
    void task()
    {
        if(_st==0)
        {
            //para apagar tareas
            return;
        }

        if(_st==1)
        {
            digitalWrite(_PIN,! digitalRead(_PIN));
            _time.reset();
            _st++;
            return;

        }
        if(_st==2)
        {
            if(_time.dt()<_periodo)
            {
                return;
            }
            _st=1;
            return;
        }
/* si se quiere parpadear en distintos tiempo se usa esto:
        if(_st==1)
        {
            digitalWrite(_PIN,HIGH);
            _time.reset();
            _st=2;
            return;

        }
        if(_st==2)
        {
            if(_time.dt()<500)
            {
                return;
            }
            _st=3;
            return;

        }
        if(_st==3)
        {
            digitalWrite(_PIN,LOW);
            _time.reset();
            _st=4;
            return;
        }
        if(_st=4)
        {
             if(_time.dt()<500)
            {
                return;
            }
            _st=1;
            return;
        }
        */
    }
}//namespace datos