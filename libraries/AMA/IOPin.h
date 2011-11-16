#ifndef IOPIN_H
#define IOPIN_H

#include "Runnable.h"

class IOPin
{
  public:
    IOPin();
    enum pinDirection { INPUT, OUTPUT };
    enum pinType { ANALOG, DIGITAL };
    enum pinMode { NONE, THROB, RAMP, BLINK };
  private:
    enum pinMode _mode;
    enum pinDirection _direction;
    enum pinType _type;
    uint8_t pinID;

};

#endif
