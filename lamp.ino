#include "IRremote.h"
#include "lamp.h"

const int ir_pin = 2;
const int red_pin = 3;
const int green_pin = 5;
const int blue_pin = 6;
const bool led_type = RGBLed::COMMON_CATHODE;

IRrecv irrecv(ir_pin);
Lamp lamp(red_pin, green_pin, blue_pin, led_type);
volatile uint32_t code;

void setup() {
  Serial.begin(9600);

  // enable receiving IR
  irrecv.enableIRIn();

  // attach IR receiving interrupt
  attachInterrupt(digitalPinToInterrupt(ir_pin), interruptIRRecv, FALLING);

  code = 0xFFFFFF;
}

void loop() {
  lamp.receive(code);
}

void interruptIRRecv() {
  if (irrecv.decode()) {
    if (irrecv.results.decode_type == NEC) {
        code = irrecv.results.value;
    }
    irrecv.resume();
  }
}
