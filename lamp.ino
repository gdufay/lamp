#include "IRremote.h"
#include "lamp.h"

const int ir_pin = 2;
const int red_pin = 5;
const int green_pin = 6;
const int blue_pin = 9;
const bool led_type = RGBLed::COMMON_CATHODE;

IRrecv irrecv(ir_pin);
Lamp lamp(red_pin, green_pin, blue_pin, led_type);

void setup() {
	Serial.begin(9600);

	// enable receiving IR
	irrecv.enableIRIn();
}

void loop() {
	if (irrecv.decode()) {
		if (irrecv.results.decode_type == NEC) {
			lamp.receive(irrecv.results.value);
		}
		irrecv.resume();
	}
	delay(100);
}
