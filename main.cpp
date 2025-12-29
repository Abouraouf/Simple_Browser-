#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"
#include "include/Render.hpp"

int main ()
{
    HtmlParser mahdi;
    try
    {
        HTMLElement *hassan = mahdi.Htmlparser("<meta tag=\"div\" x=50 y=50 width=400 height=200 color=gray />");
        print_tree(hassan);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

//drawing simple shapes

// int main()
// {
//     if (SDL_Init(SDL_INIT_VIDEO) < 0)
//         return 1;

//     Render render("Browser", SCREEN_WIDTH, SCREEN_HEIGHT);
//     SDL_Renderer* renderer = render.getRenderer();

//     bool run = true;
//     SDL_Event event;
//     SDL_Point a = {300, 300};
//     SDL_Point b = {300, 600};
//     SDL_Point c = {600, 300};
//     SDL_Point d = {600, 600};
//     while (run)
//     {
//         while (SDL_PollEvent(&event))
//         {
//             if (event.type == SDL_QUIT)
//                 run = false;
//         }
//         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
//         SDL_RenderClear(renderer);

//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//         SDL_RenderDrawLine(renderer,a.x, a.y, b.x, b.y);
//         SDL_RenderDrawLine(renderer,a.x, a.y, c.x, c.y);
//         SDL_RenderDrawLine(renderer,c.x, c.y, d.x, d.y);
//         SDL_RenderDrawLine(renderer,d.x, d.y, b.x, b.y);
        
//         // draw later

//         SDL_RenderPresent(renderer);
//     }

//     SDL_Quit();
//     return 0;
// }

