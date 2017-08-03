#include <MicroXML/MicroXML.hpp>

int main()
{
    MicroXML::setDefaultSeparator(".");
    NodeXML root = MicroXML::parse("test.xml");

    NodeSet authors   = root("catalog")("book", "/");
    NodeSet genresBis = root("catalog.book");

    root.print();

    root.saveToFile("test.test");

    std::cout << std::endl;

    return 0;
}
