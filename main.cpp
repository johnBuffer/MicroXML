#include "ParserXML.hpp"
#include "utils.hpp"

int main()
{
    //NodeXML root = ParserXML::parse("c:/standard");
    NodeXML root = ParserXML::parse("test");

    NodeSet authors = root("catalog.book");

    for (NodeXML* node : authors())
    {
        std::cout << node->get("id") << std::endl;
    }

    return 0;
}
