#include "Runnable.h"

Runnable::Runnable(Clock *c, const char *name) {
  _c = c;
  _t.setClock(_c);
  strncpy(_name, name, RUNNABLE_NAME_LEN);
  _log[0] = '\0';
  _useTimer = false;
}

void Runnable::setPeriod(float f) {
  if(f < 0.001) {
    _useTimer = false;
  } else {
    _useTimer = true;
    _period = f;
  }
}

bool Runnable::shouldRun() {
  if(_useTimer) {
    if(_t.hasFired()) {
      _t.arm(_period);
      return true;
    } else {
      return false;
    }
  }
  return true;
}

// TODO, may not need this, nuke if it's dead
void Runnable::setLog(char *l) {
  strncpy(_log, l, RUNNABLE_LOG_LEN);
}

const char * Runnable::getName() {
  return _name;
}

const char * Runnable::logMessage() {
  if(_log[0] == '\0') {
    return NULL;
  } else {
    return _log;
  }
}

void Runnable::ackLog() {
  _log[0] = '\0';
}

void ValueCore::setValue(float v) {
  _value = v;
}

void ValueCore::setTestValue(float v) {
  _testOverride = true;
  _testValue = v;
}

void ValueCore::clearTestValue() {
  _testOverride = false;
}

float ValueCore::getValue() {
  if(_testOverride) {
    return _testValue;
  } else {
    return _value;
  }
}
