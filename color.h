#ifndef COLOR_H
# define COLOR_H

// define color type
typedef int color_t[3];

// Index in colors
// NB_COLOR represents the number of colors and by extension colors size
enum ColorIndex {
	WHITE,
	RED,
	DARK_ORANGE,
	ORANGE,
	WHITE_ORANGE,
	YELLOW,
	GREEN,
	LIME,
	WHITE_CYAN,
	CYAN,
	DARK_CYAN,
	BLUE,
	MID_BLUE,
	PURPLE,
	MID_PURPLE,
	PINK,
	NB_COLOR,
};

// TODO: fix color
constexpr color_t colors[NB_COLOR] = {
  {255, 255,  255}, // WHITE
  {255, 0,  0}, // RED
  {211, 84, 0}, // DARK_ORANGE
  {255, 128,  0},  // ORANGE
  {243, 156,  18},  // WHITE_ORANGE
  {255, 255,  0}, // YELLOW
  {0,  255,  0},  // GREEN
  {0, 255,  128}, // LIME
  {0, 255,  128}, // WHITE_CYAN
  {0, 255,  255}, // CYAN
  {0, 128,  255}, // DARK_CYAN
  {0, 0,  255}, // BLUE
  {0, 128,  255}, // MID_BLUE
  {128, 0, 255}, // PURPLE
  {255, 0, 255}, // MID_PURPLE
  {255, 0,  128}, // PINK
};

#endif
