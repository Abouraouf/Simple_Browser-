#include "../../include/Render.hpp"
#include <iostream>

Render::Render(const char* title, int width, int height)
    : window(NULL), renderer(NULL)
{
    window = SDL_CreateWindow(
        title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (!window)
        std::cerr << SDL_GetError() << std::endl;

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
        std::cerr << SDL_GetError() << std::endl;
}

Render::~Render()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

SDL_Renderer* Render::getRenderer() const
{
    return renderer;
}
