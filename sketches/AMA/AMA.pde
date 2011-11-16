#include <Clock.h>
#include <Wire.h>
#include <RTClib.h>
#include <Runnable.h>

Clock c;
Timer t(&c);
//AMA ama(&c);
Runnable r(&c, "Test Device");
ValueCore v(&c, "Test Value");

void setup() {
  // put your setup code here, to run once:
r.setPeriod(0.01);
v.setValue(1);
}

void loop() {
  // put your main code here, to run repeatedly:
  //ama.run();
}
