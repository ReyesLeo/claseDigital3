#include "blinkyclass.h"
#include <Arduino.h>
void blinky::init(uint8_t pin, uint32_t periodo)
{
    pinMode(pin, OUTPUT);
    _st = toogle;
    _periodo = periodo;
    _PIN = pin;
}

void blinky::task()
{
    if (_st == shutdown)
    {
        // para apagar tareas
        return;
    }

    if (_st == toogle)
    {
        digitalWrite(_PIN, !digitalRead(_PIN));
        _time.reset();
        _st = wait;
        return;
    }
    if (_st == wait)
    {
        if (_time.dt() < _periodo)
        {
            return;
        }
        _st = toogle;
        return;
    }
}
bool blinky::detect()
{
    if (digitalRead(_PIN) == HIGH)
    {
        if (_time.dt() < _periodo)
        {
            //si es igual a 20 tendria que tener verificado que es un 1
            _time.reset();//reseto para la prox llamada
            return true;
        }else{
            return false;
        } 
    }else{
        return false;
    }
}