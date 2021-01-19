#pragma once
#include <stdlib.h>
#include <SDL.h>

class ColorM {

public:

	ColorM(void* ref);
	ColorM();
	SDL_Color RGB(int r, int g, int b);
	SDL_Color RGB(Uint32 c);
	Uint32 uRGB(int r, int g, int b);
	Uint32 uRGB(SDL_Color c);

	SDL_Color RED;
	SDL_Color BLUE;
	SDL_Color GREEN;
	SDL_Color BLACK;
	SDL_Color WHITE;
	SDL_Color YELLOW;

	Uint32 uRED;
	Uint32 uBLUE;
	Uint32 uGREEN;
	Uint32 uBLACK;
	Uint32 uWHITE;
	Uint32 uYELLOW;
	
private:
	void* window_reference;
	void init_colors();
};

enum CenterMode;