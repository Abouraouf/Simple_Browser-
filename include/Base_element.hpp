#pragma once
#include <vector>
#include <iostream>

using namespace std;

class Base_element
{
protected:
	int x;
	int y;
	int height;
	int width;
	vector <struct HTMLElement *> children;
	string text_Content;
public:
	Base_element();
	virtual ~Base_element();
};

class div : public Base_element 
{

};

class p : public Base_element 
{
	
};

class section : public Base_element 
{
	
};
class article : public Base_element 
{
	
};
class header : public Base_element 
{
	
};
class footer : public Base_element 
{
	
};

class main : public Base_element 
{
	
};

class aside : public Base_element 
{
	
};