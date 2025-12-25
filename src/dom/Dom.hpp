#pragma once

#include <string>
#include <vector>
#include <map>
#include <memory>


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
struct Element
{
	std::string type;
	std::map<std::string, std::string> attr;
};

class Elements
{

};