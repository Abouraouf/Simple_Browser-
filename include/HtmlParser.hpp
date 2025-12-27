#pragma once

#include <string>
#include <vector>
#include <cassert>
#include <iostream>
#include <unordered_set>
using namespace std;



class HTMLElement;


class HtmlParser
{
	private:
		enum State{STATE_INIT,STATE_START_TAG,STATE_READING_TAG,
  					STATE_READING_ATTRIBUTES,STATE_END_TAG,
  					STATE_BEGIN_CLOSING_TAG};
		HTMLElement	*root;
		HTMLElement	*lastparent;
		HTMLElement	*parent;
		State 		state;
    	std::string tagName;
	public:
		HtmlParser();
		HTMLElement *Htmlparser(const string& input);
		void		Html_tags(HTMLElement*& node);
		~HtmlParser();
		
};