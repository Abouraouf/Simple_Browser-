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

    for (auto child : node->children)
    {
        Base_Element* childElem = rendering_tree(child);
		if (childElem)
            elem->children.push_back(childElem);
    }

    return elem;
}

void Base_Element::render_element(SDL_Renderer* renderer)
{
    if (!renderer) return;

    // Draw this element
    SDL_Rect rect = { x, y, width, height };

    if (tagName == "div")
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);    // black for div
        cout << tagName << " x : " << x << " y : " << y << endl;
    }
    else if (tagName == "p")
    {
        SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);  // red for others
        cout << tagName << " x : " << x << " y : " << y << endl;
    }
    SDL_RenderFillRect(renderer, &rect);

    int current_y = 0;
    if (!tagName.empty())
        current_y = y + height;
    for (auto* child : children)
    {
        child->y = current_y;
        child->render_element(renderer);
        if (!tagName.empty())
            current_y += child->height + 5;
    }
}
