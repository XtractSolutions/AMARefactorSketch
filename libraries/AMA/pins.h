#ifndef PINS_H
#define PINS_H

// PIN ASSIGNMENTS
#define CHILLER_PIN 12    //output pin for the chiller
#define CHILLER_STATE_PIN 7  // taking chiller control to GRND commanding it to operat on 0-5V Input
#define CHILLER_WARNING_2_PIN 8
#define CHILLER_ERROR_PIN 10
#define CHILLER_WARNING_1_PIN 11
#define FAN_PIN 5
#define FAN_TACH_PIN 8
#define BUTTON_PIN 40
#define LED_BLUE_PIN 44
#define LED_YELLOW_PIN 46
#define LED_RED_PIN 48
#define LED_BUTTON_PIN 2
#define BUZZER_PIN 38
#define USB_SENSE_PIN 24
#define LOGGER_RESET_PIN 34

#define RTC_SDA_PIN 4 // analog
#define RTC_SCL_PIN 5 // analog

#endif
