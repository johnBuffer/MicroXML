#include "ParserXML.hpp"
#include "utils.hpp"

int main()
{
    NodeXML root = ParserXML::parse("test.xml");
    //NodeXML root = ParserXML::parse("test");

    //NodeSet authors = root("catalog.book");

    root.print();

    /*for (NodeXML* node : authors())
    {
        std::cout << node->get("id") << std::endl;
    }*/

    return 0;
}
