#pragma once
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
#include <chrono>
#include "helper.h"

class Window
{
public:

	// STRUCTS
	struct Mouse {
		int x;
		int y;
		int px;
		int py;
		int left;
		int right;
		int middle;
	};
	struct Time
	{
		float deltaTime;
		float timeScale;
		float frameBegin;
		float windowBegin;
		std::chrono::time_point<std::chrono::high_resolution_clock> _frameBegin;
	};
	struct Colors
	{
		SDL_Color text_fg;
		SDL_Color text_bg;
		SDL_Color fill;
		SDL_Color stroke;
	};
	
	// PROPERTIES
	int height;
	int width;
	int running;

	//DYNAMIC PROPERTIES
	Mouse Mouse;
	Time Time;

	// MAIN FUNCTIONS
	Window(const char* title, int width, int heigth);
	~Window();
	void enterMainLoop();
	virtual void draw();
	void updateValues();
	virtual void handle_events();

	//GETTER
	SDL_Surface* getSurface();

	//COLOR
	ColorM Color;
	void textColor(SDL_Color fg, SDL_Color bg);
	void fillColor(SDL_Color c);
	void strokeColor(SDL_Color c);

	//DRAWING FUNCTIONS
	int background(Uint32 color);
	int drawRect(int x, int y, int w, int h);
	int drawSurface(int x, int y,int w, int h, SDL_Surface* s);

	//TEXT FUNCTIONS
	int text(const char* text, int x, int y,TTF_Font* font);
	int text(const char* text, int x, int y, TTF_Font* font, SDL_Color fg, SDL_Color bg);

	//IO FUNCTIONS
	SDL_Surface* loadImageFromDisk(const char* path);

protected:

	SDL_Window* window;
	SDL_Surface* window_surface;
	SDL_Event _event;

	Colors _colors;

	std::chrono::time_point<std::chrono::high_resolution_clock> last_time;

};


SDL_Surface* loadBMPFromDisk(const char* path);
SDL_Rect* makeRect(int x, int y, int w, int h);