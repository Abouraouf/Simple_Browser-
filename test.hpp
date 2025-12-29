// #pragma once
#include <SDL2/SDL.h>
#include <stdio.h>

class test
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;
public:
    test(const char* title, int width, int height);
    SDL_Renderer* GetRenderer();
    void close();
};

