#include <MicroXML/MicroXML.hpp>

int main()
{
    MicroXML::setDefaultSeparator(".");
    NodeXML root = MicroXML::parse("test.xml");

    NodeSet authors   = root("catalog")("book/title", "/");
    NodeSet genresBis = root("catalog/book/author");

    for (auto node : authors)
    {
        std::cout << node->asString() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
