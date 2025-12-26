#pragma once

#include <string>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

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
  string closing_tag;
  vector<struct HTMLElement *> children;
  struct HTMLElement *parentElement;
  string textContent;
  string parse_error;
};

HTMLElement *HTMLParser(string input);