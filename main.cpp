#include "include/Dom.hpp"
#include "include/HtmlParser.hpp"
#include "include/Utils.hpp"

int main ()
{
  HtmlParser html;
  HTMLElement* mahdi =  html.Htmlparser("<div> <h1> <p>Text</p> </h2> </div>");
  print_tree(mahdi);
}