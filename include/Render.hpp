#pragma once
#include <SDL2/SDL.h>

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 800

class Render
{
private:
    SDL_Window* window;
    SDL_Renderer* renderer;

public:
    Render(const char* title, int width, int height);
    ~Render();

    SDL_Renderer* getRenderer() const;
};
