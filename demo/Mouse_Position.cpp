#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include "Window.h"


class myWindow : public Window {

    myWindow(const char* title, int width, int height) : Window(title, width, height){
        f = TTF_OpenFont("C:\\Windows\\Fonts\\arial.ttf",32);

        textColor(Color.WHITE, Color.BLACK);
        SDL_ShowCursor(0);
    }


    void draw() override {
        //Fills the background
        background(Color.uBLACK);

        //Mouse Position as String
        char str [2];
        sprintf_s(str,"(%d,%d)",Mouse.x,Mouse.y);

        //Displays the Mouse Position at the Mouse Position
        text(str,Mouse.x,Mouse.y,f);
    }

};

int main(int argc, char* args[])
{
    //                          TITLE   WIDTH  HEIGHT
    myWindow w = *new myWindow("TITLE",  500,   500);
    w.enterMainLoop();
    return 0;
}
