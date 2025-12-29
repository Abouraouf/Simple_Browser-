#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"
#include "include/Render.hpp"


int main()
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return 1;

    Render render("Browser", SCREEN_WIDTH, SCREEN_HEIGHT);
    SDL_Renderer* renderer = render.getRenderer();

    bool run = true;
    SDL_Event event;

    while (run)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                run = false;
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        // draw later

        SDL_RenderPresent(renderer);
    }

    SDL_Quit();
    return 0;
}

