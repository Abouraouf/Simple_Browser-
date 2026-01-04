#include "../../include/Base_Element.hpp"
#include "../../include/Elements.hpp"
#include "../../include/Dom.hpp"
#include "../../include/Render.hpp"

Base_Element::Base_Element() : x(0), y(0), height(20), width(100), tagName(""){}

Base_Element::~Base_Element()
{
	for(auto child : children){
		delete child;
		child = NULL;
	}
}

const string& Base_Element::Get_tagname()
{
	return (tagName);
}

const vector<Base_Element*>& Base_Element::Get_children()
{
	return children;
}

Base_Element* Base_Element::rendering_tree(HTMLElement* node, int depth)
{
    (void) depth;
    if (!node)
        return NULL;

    Base_Element* elem = nullptr;
    elem = new Base_Element();

    elem->x = 0;
    elem->y = 0;
    elem->width = 100;
    elem->height = 20;
	elem->tagName = node->tagName;
    elem->text_Content = node->textContent;

    for (auto child : node->children)
    {
        Base_Element* childElem = rendering_tree(child);
		if (childElem)
            elem->children.push_back(childElem);
    }

    return elem;
}

void Base_Element::render_element(SDL_Renderer* renderer, TTF_Font& font)
{
    if (!renderer) return;

    // Draw this element
    // SDL_Rect rect = { x, y, width, height };

    if (tagName == "div")
        cout << tagName << " x : " << x << " y : " << y << endl;
    else if (tagName == "p")
        cout << tagName << " x : " << x << " y : " << y << endl;
    // SDL_RenderFillRect(renderer, &rect);
    
    int current_y = 0;
    if (!tagName.empty())
        current_y = y + height;
    render_TextContent(renderer, font);
    for (auto* child : children)
    {
        child->y = current_y;
        child->render_element(renderer, font);
        if (!tagName.empty())
            current_y += child->height + 5;
    }
}

void  Base_Element::render_TextContent(SDL_Renderer* renderer, TTF_Font& font)
{
    if (!text_Content.empty())
    {
        SDL_Color color = {0, 0, 0, 255}; // white text
        SDL_Surface* surface = TTF_RenderText_Blended(&font, text_Content.c_str(), color);
        if (surface)
        {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
            SDL_Rect textRect = { x, y, surface->w, surface->h }; // small padding
            SDL_RenderCopy(renderer, texture, nullptr, &textRect);
            SDL_FreeSurface(surface);
            SDL_DestroyTexture(texture);
        }
    }
}