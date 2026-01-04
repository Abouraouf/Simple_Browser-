#pragma once
#include <vector>
#include <iostream>
#include "Dom.hpp"
#include "Render.hpp"
using namespace std;

struct SDL_Renderer;  // forward declaration


class Base_Element
{
protected:
	int x;
	int y;
	int height;
	int width;
	string tagName;
	vector <Base_Element*> children;
	string text_Content;
public:
	Base_Element();
	const string& Get_tagname();
	const vector <Base_Element*>& Get_children();
	static Base_Element* rendering_tree(HTMLElement* node, int depth = 0);
	
	//rendering

	virtual void render_element(SDL_Renderer* renderer, TTF_Font& font);
	virtual void render_TextContent(SDL_Renderer* renderer, TTF_Font& font);
	
	virtual ~Base_Element();
};
