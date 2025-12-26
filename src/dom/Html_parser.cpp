#include "../../include/Dom.hpp"
#include "../../include/HtmlParser.hpp"

//constructor and distructor
HtmlParser::HtmlParser()
{
  try {
    root = new HTMLElement;
  }
  catch (const std::bad_alloc& e){
    std::cerr << "Allocation failed in constructor" << std::endl;
  }
  lastparent = root;
  state = STATE_INIT;
}

HtmlParser::~HtmlParser()
{
	delete root;
}

// checking errors
bool  HtmlParser::check_closing_tag(const char* input)
{
    cout << input << endl;
    return true;
}

//parser
HTMLElement *HtmlParser::Htmlparser(string input)
{
  string tagName = "";
  for (auto c : input) {
    if (c == '<') {
      state = STATE_START_TAG;
    } else if (state == STATE_START_TAG) {
      if (c == '/') {
        state = STATE_BEGIN_CLOSING_TAG;
      } else if (!std::isspace(c)) {
        state = STATE_READING_TAG;
        tagName = c;
      }
    } else if (state == STATE_READING_TAG) {
      if (std::isspace(c)) {
        state = STATE_READING_ATTRIBUTES;
      } else if(c == '>') {
        state = STATE_END_TAG;

        auto parent = new HTMLElement(); 
        parent->tagName = tagName;
        parent->parentElement = lastparent;

        lastparent->children.push_back(parent);
        lastparent = parent;
      } else {
        tagName += c;
      }
    } else if(state == STATE_READING_ATTRIBUTES) {
      if (c == '>') {
        state = STATE_END_TAG;

        HTMLElement* parent = new HTMLElement(); 
        parent->tagName = tagName;
        parent->parentElement = lastparent;
        
        lastparent->children.push_back(parent);
        lastparent = parent;
      }
    } else if (state == STATE_END_TAG) {
      lastparent->textContent += c;
    } else if (state == STATE_BEGIN_CLOSING_TAG) {
          if (c != '>') {
        lastparent->closing_tag += c;  // keep accumulating the closing tag name
    } else { // closing tag finished
        // Walk up the tree to find a matching open tag
        HTMLElement* node = lastparent;
        while (node && node->tagName != lastparent->closing_tag) {
            node->parse_error = "Expected </" + node->tagName + "> but found </" + lastparent->closing_tag + ">";
            node = node->parentElement;
        }
        if (node) {
            lastparent = node->parentElement; // properly close the matching node
            
        }
        lastparent->closing_tag.clear(); // reset for next closing tag
        state = STATE_END_TAG;            // back to normal text state
    }
    }
  }
  return root;
}
