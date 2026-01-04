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

    // ---- Add SDL_ttf initialization and font loading here ----
    if (TTF_Init() == -1) {
        std::cerr << "TTF_Init Error: " << TTF_GetError() << std::endl;
        return;
    }
    TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/dejavu/DejaVuMathTeXGyre.ttf", 16);
    if (!font) {
        std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
        return;
    }
    // ----------------------------------------------------------

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

        root->render_element(renderer, *font); // pass font to render_element

        SDL_RenderPresent(renderer);
    }

    // Cleanup
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}


int main ()
{
    HtmlParser mahdi;
    string html = "<div>"      // Div at (0,0)
              "<p>this is a paragraph</p> "    // P at (0,20)
              "<div> "      // Nested Div at (0,45)
                  "<p>paragraph 3</p> " // P at (0,90)
              "</div> "
              "<p> paragraph 4</p> "    // P at (0,115)
                "<div>"
                "<p> paragraph 5 </p>"
                "</div>"
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