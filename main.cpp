#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"

int main ()
{
  HtmlParser html;
  // std::string html = "<div> <h1> <p>Text</p> </h1> </div>";
  HTMLElement* mahdi =  html.Htmlparser("<html><body><h1>Title<div id=\"main\" class=\"test\"><p>Hello <em>world</em>!</p></div></body></html>");
  print_tree(mahdi);
}
