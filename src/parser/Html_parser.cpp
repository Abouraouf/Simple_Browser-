#include "../../include/Dom.hpp"
#include "../../include/HtmlParser.hpp"

//constructor and distructor
HtmlParser::HtmlParser()
{
    root = new HTMLElement;
  	lastparent = root;
  	state = STATE_INIT;
	// continu later
}

HtmlParser::~HtmlParser()
{
	delete root;
}

void HtmlParser::Html_tags(HTMLElement*& node)
{
     static const unordered_set<std::string> normalTags = {
        "html","head","body","div","p","h1","h2","h3","h4","h5","h6",
        "span","a","ul","ol","li","section","article","header","footer",
        "nav","main","aside","strong","em","title"
    };

    static const unordered_set<std::string> selfClosing = {
        "br","hr","img","input","link","meta"
    };
    if(normalTags.count(node->tagName))
	{
        node->tag_type = TAG_NORMAL;
	}
	else if (selfClosing.count(node->tagName))
	{
        node->tag_type = TAG_SELF_CLOSING;
	}
	else
    {
		node->tag_type = TAG_UNKNOWN;
	    node->parse_error = std::string("Unknown tag <") + node->tagName + "> encountered";
    }
}


void parent_creation(const std::string& tagName, HTMLElement*& lastparent)
{
  HTMLElement *parent = new HTMLElement();
  parent->parentElement = lastparent;
  parent->tagName = tagName;
  lastparent->children.push_back(parent);
	HtmlParser::Html_tags(parent);
	if (parent->tag_type != TAG_SELF_CLOSING)
		lastparent = parent;
}

//checks for unmatched tags
void	check_unmatched_tags(HTMLElement*& lastparent) // check this when you come back
{
	HTMLElement* node = lastparent;
    while (node && node->tagName != lastparent->closing_tag) {
		  node->parse_error = "Expected </" + node->tagName + "> but found </" + lastparent->closing_tag + ">";
      node = node->parentElement;
    }

    if (node) {
        lastparent = node->parentElement;
    }
}

//parser
HTMLElement *HtmlParser::Htmlparser(const string& input)
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
        parent_creation(tagName, lastparent);
      } else {
        if (c != '/')
          tagName += c;
      }
    } else if(state == STATE_READING_ATTRIBUTES) {
      if (c == '>') {
        state = STATE_END_TAG;
        parent_creation(tagName, lastparent);
        if (lastparent->tag_type == TAG_SELF_CLOSING)
        	state = STATE_END_TAG;
      }
    } else if (state == STATE_END_TAG) {
      lastparent->textContent += c;
    } else if (state == STATE_BEGIN_CLOSING_TAG) {
          if (c != '>') {
        lastparent->closing_tag += c;
    } else {
        check_unmatched_tags(lastparent);
        lastparent->closing_tag.clear();
        state = STATE_END_TAG;
        }
        }
    }
  return root;
}
