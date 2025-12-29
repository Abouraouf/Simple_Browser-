#include "../../include/Base_element.hpp"

Base_element::Base_element() : x(0), y(0), width(100), height(20) {}

Base_element::~Base_element()
{
	for(auto child : children){
		delete child;
		child = NULL;
	}
}

