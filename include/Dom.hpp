#pragma once

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

enum HtmlTag {TAG_UNKNOWN = -1, TAG_NORMAL, TAG_SELF_CLOSING};

class NodeType
{
	public:
		virtual ~NodeType() {};
};

class Texttype : public NodeType
{
	private:
		std::string Data;
	public:
		Texttype(std::string& d): Data(d) {}
};

// the element should have a type, 


class HTMLElement
{
public:
  string tagName;
  HtmlTag tag_type;
  string closing_tag;
  vector<struct HTMLElement *> children;
  struct HTMLElement *parentElement;
  string textContent;
  string parse_error;
};
