#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"

int main ()
{
  HtmlParser html;
  try
  {
  	HTMLElement* mahdi =  html.Htmlparser("<html><head><asd></asd><title>Test Page</title></head><body><h1>Main Title</h1><div><h2>Section One</h2><p>This is a paragraph with <b>bold</b> text.</p><div><h3>Subsection</h3><p>Another paragraph.</p></div></div><div><h2>Section Two</h2><p>Nested text <span>inside a span</span> continues here.</p><ul><li>Item one</li><li>Item two</li><li>Item three</li></ul></div><footer><p>Footer content</p></footer></body></html>");
  	print_tree(mahdi);
  }
  catch (const std::exception& e)
  {
	std::cout << e.what() << std::endl;
  }
}
