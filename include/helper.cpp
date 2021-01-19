#pragma once
#include "helper.h"
#include "Window.h"

// CLASS COLOR

ColorM::ColorM(void* ref)
{
    this->window_reference = ref;
	this->init_colors();
}

ColorM::ColorM()
{
	this->init_colors();
}

Uint32 ColorM::uRGB(int r, int g, int b)
{
	if(((Window*)this->window_reference)->getSurface())
    return SDL_MapRGB(((Window*)this->window_reference)->getSurface()->format,r,g,b);
	else return NULL;
}

Uint32 ColorM::uRGB(SDL_Color c)
{
	return SDL_MapRGB(((Window*)this->window_reference)->getSurface()->format, c.r, c.g, c.b);
}

SDL_Color ColorM::RGB(int r, int g, int b)
{
	return SDL_Color{(Uint8)r,(Uint8)g,(Uint8)b};
}

SDL_Color ColorM::RGB(Uint32 c)
{
	SDL_Color out;
	SDL_GetRGB(c, ((Window*)this->window_reference)->getSurface()->format,&out.r,&out.g,&out.b);
	return out;
}

void ColorM::init_colors()
{
	RED = this->RGB(255, 0, 0);
	BLUE = this->RGB(0, 0, 255);
	GREEN = this->RGB(0, 255, 0);
	BLACK = this->RGB(0,0,0);
	WHITE = this->RGB(255, 255, 255);
	YELLOW = this->RGB(255, 255, 0);

	uRED = this->uRGB(255, 0, 0);
	uBLUE = this->uRGB(0, 0, 255);
	uGREEN = this->uRGB(0, 255, 0);
	uBLACK = this->uRGB(0, 0, 0);
	uWHITE = this->uRGB(255, 255, 255);
	uYELLOW = this->uRGB(255, 255, 0);
}



// END CLASS COLOR



enum CenterMode {
	DEFAULT,
	CENTER
};