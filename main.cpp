#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"

int main ()
{
  std::string html = "<html><head><title>Sample Page</title><meta charset=\"UTF-8\" /><link rel=\"stylesheet\" href=\"style.css\" /></head><body><header><h1>Welcome to My Page</h1><nav><ul><li><a href=\"#\">Home</a></li><li><a href=\"#\">About</a></li><li><a href=\"#\">Contact</a></li></ul></nav></header><main><section><h2>Section Title</h2><p>This is a paragraph with <strong>strong</strong> and <em>emphasized</em> text.<br /></p><img src=\"image.png\" /><input type=\"text\" placeholder=\"Your name\" /><p>This paragraph has no closing tag</section></main><footer><p>Footer content here<hr /></p></footer></body></html>";

  try
  {
    HtmlParser hh;
  	HTMLElement* mahdi =  hh.Htmlparser(html);
  	print_tree(mahdi);
  }
  catch (const std::exception& e)
  {
	std::cout << e.what() << std::endl;
  }
}
