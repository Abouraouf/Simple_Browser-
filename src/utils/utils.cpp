#include "../../include/Utils.hpp"

void print_tree(HTMLElement* node, int depth)
{
    if (!node) return;

    for (int i = 0; i < depth; i++)
        cout << "  ";

    if (!node->tagName.empty())
      {
    cout << "<" << node->tagName << ">";
      }
    if (!node->textContent.empty())
        cout << " : " << node->textContent;
    else
        cout << "it is empty" << endl;
    if (!node->closing_tag.empty())
      cout << " </" << node->closing_tag << ">" << endl;
    cout << "\n";

    for (auto child : node->children)
        print_tree(child, depth + 1);
}
