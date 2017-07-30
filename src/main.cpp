#include <MicroXML/MicroXML.hpp>

int main()
{
    MicroXML::setDefaultSeparator(".");
    NodeXML root = MicroXML::parse("test.xml");

    NodeSet authors   = root("catalog")("book/title", "/");
    NodeSet genresBis = root("catalog.book");

    for (auto node : genresBis)
    {
        std::cout << node["id"] << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
