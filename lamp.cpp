#include "lamp.h"

int Lamp::FLASH_DURATION = 500;
int Lamp::STROBE_DURATION = 1000;

Lamp::Lamp(int const red_pin, int const green_pin, int const blue_pin, bool const led_type) : _led(red_pin, green_pin, blue_pin, led_type), _intensity(100), _action(0)
{
	// set color to white by default
	setColor(ColorIndex::WHITE);

	// turn off led at initialisation
	_led.off();
}

// helper function which return true if search is find in array
inline bool in_array(uint32_t const arr[], uint32_t const search) {
	for (size_t i = 0; i < sizeof(arr) / sizeof(*arr); ++i) {
		if (arr[i] == search)
			return true;
	}
	return false;
}

void Lamp::receive(uint32_t const action) {
	static const uint32_t one_time_action[] = {
		POWER_ON, POWER_OFF, LIGHT_UP, LIGHT_DOWN, SET_WHITE, SET_RED,
		SET_DARK_ORANGE, SET_ORANGE, SET_WHITE_ORANGE, SET_YELLOW,
		SET_GREEN, SET_LIME, SET_WHITE_CYAN, SET_CYAN, SET_DARK_CYAN,
		SET_BLUE, SET_MID_BLUE, SET_PURPLE, SET_MID_PURPLE, SET_PINK,
	};
	static const uint32_t multiple_time_action[] = {
		FLASH, STROBE, FADE, SMOOTH,
	};

	if (action == _action && in_array(one_time_action, action))
		return ;

	_action = action;
	switch (action) {
		case POWER_ON:
			color();
			break ;
		case POWER_OFF:
			_led.off();
			break ;
		case LIGHT_UP:
			lightUp();
			break ;
		case LIGHT_DOWN:
			lightDown();
			break ;
		case FLASH:
			flash();
			break ;
		case STROBE:
			strobe();
			break ;
		case FADE:
			fade();
			break ;
		case SMOOTH:
			smooth();
			break ;
		case SET_WHITE:
			setColor(ColorIndex::WHITE);
			break ;
		case SET_RED:
			setColor(ColorIndex::RED);
			break ;
		case SET_DARK_ORANGE:
			setColor(ColorIndex::DARK_ORANGE);
			break ;
		case SET_ORANGE:
			setColor(ColorIndex::ORANGE);
			break ;
		case SET_WHITE_ORANGE:
			setColor(ColorIndex::WHITE_ORANGE);
			break ;
		case SET_YELLOW:
			setColor(ColorIndex::YELLOW);
			break ;
		case SET_GREEN:
			setColor(ColorIndex::GREEN);
			break ;
		case SET_LIME:
			setColor(ColorIndex::LIME);
			break ;
		case SET_WHITE_CYAN:
			setColor(ColorIndex::WHITE_CYAN);
			break ;
		case SET_CYAN:
			setColor(ColorIndex::CYAN);
			break ;
		case SET_DARK_CYAN:
			setColor(ColorIndex::DARK_CYAN);
			break ;
		case SET_BLUE:
			setColor(ColorIndex::BLUE);
			break ;
		case SET_MID_BLUE:
			setColor(ColorIndex::MID_BLUE);
			break ;
		case SET_PURPLE:
			setColor(ColorIndex::PURPLE);
			break ;
		case SET_MID_PURPLE:
			setColor(ColorIndex::MID_PURPLE);
			break ;
		case SET_PINK:
			setColor(ColorIndex::PINK);
			break ;
		default:
			break ;
	}
}

void Lamp::lightUp() {
	_intensity += 10;

	if (_intensity > 100) {
		_intensity = 100;
	}

	color();
}

void Lamp::lightDown() {
	_intensity -= 10;

	if (_intensity < 0) {
		_intensity = 0;
	}

	color();
}

void Lamp::setColor(color_t const & new_color) {
	for (byte i = 0; i < sizeof(new_color) / sizeof(*new_color); ++i) {
		_color[i] = new_color[i];
	}
	color();
}

void Lamp::setColor(ColorIndex const & color) {
	setColor(colors[color]);
}

void Lamp::flash() const {
	// TODO: replace by color: use with millis() to not use delay
	for (int i = 0; i < ColorIndex::NB_COLOR; ++i) {
		_led.flash(colors[i], FLASH_DURATION);
	}
}

void Lamp::strobe() const {
	_led.flash(colors[ColorIndex::WHITE], STROBE_DURATION);
}

void Lamp::fade() const {
	// TODO
}

void Lamp::smooth() const {
	fade();
}

void Lamp::color() const {
	_led.brightness(_color, _intensity);
}
