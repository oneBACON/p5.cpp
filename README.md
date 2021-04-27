## p5.cpp   |   Processing in C++

A libary for SDL OpenGL to immitate the look and feel of Processing / p5.js

Supports all major functions and concepts of P5 while keeping the speed and flexibility of C++.

# Install

* Copy the include files to your include directory.
* Use the starting Project down below.
* Enjoy!

# Start Project
```cpp
#include "Window.h"

class myWindow : public Window {

    void setup() override{

    }


    void draw() override {

    }

};

int main(int argc, char* args[])
{
    myWindow w = *new myWindow();
    w.enterMainLoop();
    return 0;
}

```

