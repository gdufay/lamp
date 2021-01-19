#ifndef LAMP_H
# define LAMP_H

# include "RGBLed.h"
# include "color.h"

// code send by remote
constexpr uint32_t POWER_ON = 0xF7C03F;
constexpr uint32_t POWER_OFF = 0xF740BF;
constexpr uint32_t LIGHT_UP = 0xF700FF;
constexpr uint32_t LIGHT_DOWN = 0xF7807F;
constexpr uint32_t FLASH = 0xF7D02F;
constexpr uint32_t STROBE = 0xF7F00F;
constexpr uint32_t FADE = 0xF7C837;
constexpr uint32_t SMOOTH = 0xF7E817;
constexpr uint32_t SET_WHITE = 0xF7E01F;
constexpr uint32_t SET_RED = 0xF720DF;
constexpr uint32_t SET_DARK_ORANGE = 0xF710EF;
constexpr uint32_t SET_ORANGE = 0xF730CF;
constexpr uint32_t SET_WHITE_ORANGE = 0xF708F7;
constexpr uint32_t SET_YELLOW = 0xF728D7;
constexpr uint32_t SET_GREEN = 0xF7A05F;
constexpr uint32_t SET_LIME = 0xF7906F;
constexpr uint32_t SET_WHITE_CYAN = 0xF7B04F;
constexpr uint32_t SET_CYAN = 0xF78877;
constexpr uint32_t SET_DARK_CYAN = 0xF7A857;
constexpr uint32_t SET_BLUE = 0xF7609F;
constexpr uint32_t SET_MID_BLUE = 0xF750AF;
constexpr uint32_t SET_PURPLE = 0xF7708F;
constexpr uint32_t SET_MID_PURPLE = 0xF748B7;
constexpr uint32_t SET_PINK = 0xF76897;

class Lamp {
	public:
		Lamp(int const red_pin, int const blue_pin, int const green_pin, bool const led_type);

		void receive(uint32_t const action);

		// different mode duration
		static int FLASH_DURATION;
		static int STROBE_DURATION;

	protected:
		// protected functions called by received
		void lightUp();		// increase light intensity
		void lightDown();	// decrease light intensity

		void setColor(color_t const & color);		// set _color
		void setColor(ColorIndex const & color);	// set _color

		void flash() const;	// put in flash mode
		void strobe() const;	// put in strobe mode
		void fade() const;	// put in fade mode
		void smooth() const;	// put in smooth mode
		void color() const;	// color led with _color and _intensity

		// private variables
		RGBLed _led;
		int _intensity;
		color_t _color;
		uint32_t _action;
};

#endif
