#include <Arduino.h>
//#include "timeR.h"
//#include "class_timer.h"
//#include "led_task.h"
#include "blinkyclass.h"
//TIMER contador;
blinky blinky1;
blinky boton;
//hacer un anti rebote, que espera 20ms, si esta en alto despues de esos 20ms significa que si se apreto botn, si no es ruido
void encendido()
{
   digitalWrite(LED_BUILTIN,HIGH);
  if(digitalRead(LED_BUILTIN)==HIGH)
  {
    digitalWrite(LED_BUILTIN,LOW);
  }else{
    digitalWrite(LED_BUILTIN,HIGH);
  }
}
//ledbuiltin pin 2
void setup() {
  Serial.begin(115200);
  Serial.println("testeo");
  // put your setup code here, to run once:
  //int result = myFunction(2, 3);
  //micros();lo mismo que milli pero en microseg,32bits->2^32->49.7dias aprxo
  /*clase 1
  Serial.begin(9600);
  Serial.println("hollll");
  tick=millis();//tiempo desde que se inicia el micro*/
  //clase 2
  //datos::ini(2,250);
  //pinMode(LED_BUILTIN,OUTPUT);
  //contador.reset();
  blinky1.init(2,1000);//led
  boton.init(3,20);
 
  //Reset();
  //cont=(uint32_t)(~millis())+1UL; //el tamño del 1 depende del dispositivo que se use, por eso se usa 1UL para aclarar que es unsigned long
 //tambien podria usar (uint32_t)1
}
void loop() {
  // put your main code here, to run repeatedly:
  /* classe 1
  uint32_t tock=millis();
  if((tock-tick)>100)
  {
    Serial.println("paso 100ms");
  }
  */
  /*if(contador.dt()>250)
  {
    contador.reset();
    encendido();
  }*/
  //datos::task();
  blinky1.task();
  if(boton.detect())
  {
    //enciendo led
  }else{
    //no o hago nada
  }
}