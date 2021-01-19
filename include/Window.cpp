#pragma once
#include "Window.h"
#include <SDL_ttf.h>
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>


//CLASS WINDOW

Window::Window(const char* title, int width, int height)
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		std::cout << "Failed to initialize the SDL2 library\n";
	}
	if (TTF_Init() != 0) {
		std::cout << "Failed to initialize the SDL2_TTF library\n";
	}

	Mouse = { 0,0,0,0,0 };

	this->width = width;
	this->height = height;
	running = 1;

	window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
	window_surface = SDL_GetWindowSurface(window);

	Color = *new ColorM(this);

	Time.windowBegin = ((std::chrono::duration<float>)std::chrono::high_resolution_clock::now().time_since_epoch()).count();

}

Window::~Window()
{
	SDL_FreeSurface(window_surface);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

SDL_Surface* Window::getSurface()
{
	if (this)
		return window_surface;
	else return nullptr;
}

void Window::textColor(SDL_Color fg, SDL_Color bg)
{
	_colors.text_fg = fg;
	_colors.text_bg = bg;
}

void Window::fillColor(SDL_Color c)
{
	_colors.fill = c;
}

void Window::strokeColor(SDL_Color c)
{
	_colors.stroke = c;
}

int Window::background(Uint32 color)
{
	return SDL_FillRect(window_surface, NULL, color);
}

int Window::drawRect(int x, int y, int w, int h)
{
	return SDL_FillRect(window_surface, makeRect(x, y, w, h), Color.uRGB(_colors.fill));
}

int Window::drawSurface(int x, int y, int w, int h, SDL_Surface* s)
{
	return SDL_BlitSurface(s, NULL, window_surface, makeRect(x, y, w, h));;
}

int Window::text(const char* text, int x, int y, TTF_Font* font) {
	SDL_Surface* s = TTF_RenderText_Shaded(font, text, _colors.text_fg, _colors.text_bg);
	return SDL_BlitSurface(s, NULL, window_surface, makeRect(x, y, 0, 0));
}

SDL_Surface* Window::loadImageFromDisk(const char* path)
{

	return IMG_Load(path);

}

void Window::draw() {

}

void Window::handle_events() {
	while (SDL_PollEvent(&_event) > 0)
	{
		switch (_event.type)
		{
		case SDL_QUIT:
			this->running = false;
			break;
		}
	}
}

void Window::enterMainLoop()
{
	while (running)
	{

		updateValues();
		draw();
		handle_events();
		SDL_UpdateWindowSurface(window);

	}
}


void Window::updateValues()
{
	Mouse.px = Mouse.x;
	Mouse.py = Mouse.y;
	int i = SDL_GetMouseState(&Mouse.x, &Mouse.y);
	Mouse.left = i & SDL_BUTTON(SDL_BUTTON_LEFT);
	Mouse.right = i & SDL_BUTTON(SDL_BUTTON_RIGHT);
	Mouse.middle = i & SDL_BUTTON(SDL_BUTTON_MIDDLE);


	auto now = std::chrono::high_resolution_clock::now();
	Time.deltaTime = ((std::chrono::duration<float>)(now - Time._frameBegin)).count();
	Time._frameBegin = now;
	Time.frameBegin = ((std::chrono::duration<float>)now.time_since_epoch()).count();
}

//END CLASS WINDOW



SDL_Rect* makeRect(int x, int y, int w, int h) {
	SDL_Rect a = SDL_Rect{ x,y,w,h };
	return &a;
}
SDL_Surface* loadBMPFromDisk(const char* path) {
	SDL_Surface* image = SDL_LoadBMP(path);

	if (!image)
	{
		std::cout << "Failed to load image\n";
		std::cout << "SDL2 Error: " << SDL_GetError() << "\n";
		return nullptr;
	}
	return image;
}