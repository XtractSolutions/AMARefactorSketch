#include <Clock.h>
#include <stdio.h>
#include <string.h>

extern "C" {
#include "WConstants.h"
}

Clock::Clock() {
  _millis = 0;
  _seconds = 0;
  _lastMillis = 0;
}

void Clock::run() {
  _millis = millis();
  if(_millis - _lastMillis > 500) { // keep the cached RTC fresh every 1/2 second or so
    // will lag 500ms 1x a month when the millis counter rolls over :)
    _now = RTC.now();
    _seconds = _now.unixtime();
  }
  _lastMillis = _millis;
}

uint32_t Clock::cachedMillis() {
  return _millis;
}

uint32_t Clock::cachedSeconds() {
  return _seconds;
}

char * Clock::dateHMS() {
  char dateStr[50];
  sprintf(dateStr, "%04d/%02d/%02d %02d:%02d:%02d", _now.year(), _now.month(), _now.day(), _now.hour(), _now.minute(), _now.second());
  return dateStr;
}

char * Clock::dateHM() {
  char dateStr[50];
  sprintf(dateStr, "%04d/%02d/%02d %02d:%02d", _now.year(), _now.month(), _now.day(), _now.hour(), _now.minute());
  return dateStr;
}

Timer::Timer() {
  _armed = false;
  _millisMode = false;
  _setTime = 0;
  _fireTime = 0;
}

Timer::Timer(Clock *c) {
  Timer();
  setClock(c);
}

void Timer::setClock(Clock *c) {
  _c = c;
}

void Timer::arm(float sec) {
  // see if the int part is more than 50ms off from an int
  _millisMode = false;
  uint16_t intPart = int(sec);
  float floatPart = sec - intPart;
  if(floatPart > 0.99) {
    intPart++;
  } else if(floatPart > 0.01) {
    _millisMode = true;
      _setTime = _c->cachedMillis();
      _fireTime = _setTime + 1000*sec;
  }

  if(!_millisMode) {
    _setTime = _c->cachedSeconds();
    _fireTime = _setTime + intPart;
  }

  _armed = true;
}

void Timer::reset() {
  _armed = false;
}

bool Timer::hasFired() {
  if(!_armed) {
    return false;
  }

  if(_millisMode) {
    if(_setTime > _fireTime) { // millis wrapped
      if(_c->cachedMillis() > _fireTime && _c->cachedMillis() < _setTime) {
        return true;
      } else {
        return false;
      } 
    } else {
      if(_c->cachedMillis() > _fireTime) {
        return true;
      } else { return false; }
    }
  } else {
    if(_c->cachedSeconds() > _fireTime) {
      return true;
    } else {
      return false;
    }
  }
}
