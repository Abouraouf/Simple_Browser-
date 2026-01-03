#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"
#include "include/Render.hpp"
#include "include/Base_Element.hpp"

void rendering(Base_Element* root)
{
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
        return ;

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
        root->render_element(renderer);
        
        // draw later

        SDL_RenderPresent(renderer);
    }
    SDL_Quit();
}

int main ()
{
    HtmlParser mahdi;
    string html = "<div> "      // Div at (0,0)
              "<p></p> "    // P at (0,20)
              "<div> "      // Nested Div at (0,45)
                  "<p></p> " // P at (0,65)
                  "<p></p> " // P at (0,90)
              "</div> "
              "<p></p> "    // P at (0,115)
           "</div>";


    HTMLElement *hassan = mahdi.Htmlparser(html);
    Base_Element* render = Base_Element::rendering_tree(hassan);
    print_tree(hassan);
    // print_tree_render(render);
    rendering(render);
       
    return 0;
}

//drawing simple shapes



// we have a segfault in here :     string html = "<<<</</><<html><body><div><p>Hello<br /></p><img src=\"x.png\" /><input type=\"text\" /><custom>Oops</custom><weirdtag></weirdtag></div></body></html>";