#ifndef Clock_h
#define Clock_h

#include <inttypes.h>
#include "pins.h"
#include <RTClib.h>

class Clock
{
  private:
    uint32_t _millis;
    uint32_t _seconds;
    uint32_t _lastMillis;
    DateTime _now;
  public:
    Clock();
    uint32_t cachedMillis();
    uint32_t cachedSeconds();
    void run();
    char *dateHMS();
    char *dateHM();
    RTC_DS1307 RTC; // allow raw access to this if needed
};

class Timer
{
  private:
    Clock *_c;
    bool _armed;
    bool _millisMode;
    uint32_t _setTime;
    uint32_t _fireTime;

  public:
    Timer(Clock *);
    Timer();
    void setClock(Clock *);
    void arm(float);
    bool hasFired();
    void reset();

};


#endif
