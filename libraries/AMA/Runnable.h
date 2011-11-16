#ifndef RUNNABLE_H
#define RUNNABLE_H

#include <string.h>
#include "Clock.h"

#define RUNNABLE_NAME_LEN 20
#define RUNNABLE_LOG_LEN 60

class Runnable {
  private:
    Clock *_c;
    char _name[RUNNABLE_NAME_LEN];
    char _log[RUNNABLE_LOG_LEN];
    Timer _t;
    float _period;
    bool _useTimer;
  protected:
    void setLog(char *);
    bool shouldRun();
  public:
    Runnable(Clock *c, const char *name);
    void setPeriod(float f);
    virtual void run() { };
    const char * getName();
    const char * logMessage();
    void ackLog();
};

class ValueCore : public Runnable {
  public:
    ValueCore(Clock *c, const char *name) : Runnable(c, name) {
      _testOverride = false;
      _value = 0.0;
    };
    virtual void setValue(float);
    virtual float getValue();
    void setTestValue(float);
    bool testValueActive();
    void clearTestValue();
  private:
    float _value;
    float _testValue;
    bool _testOverride;
};

#endif
