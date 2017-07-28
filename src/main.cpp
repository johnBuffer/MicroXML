#include <MicroXML/MicroXML.hpp>

int main()
{
    MicroXML::setDefaultSeparator("/");
    NodeXML root = MicroXML::parse("test.xml");

    NodeSet authors   = root("catalog/book");
    NodeSet genresBis = root("catalog/book/author");

    for (auto node : authors)
    {
        std::cout << node("title")[0].asString() << " (id " << node["id"] << ") written by " << node("author")[0].asString() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
