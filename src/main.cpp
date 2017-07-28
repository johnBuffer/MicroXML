#include <MicroXML/MicroXML.hpp>

int main()
{
    NodeXML root = MicroXML::parse("test.xml");

    NodeSet authors    = root["catalog"]["book"]["author"];
    NodeSet genresBis = root("catalog.book.genre");

    for (auto node : authors)
    {
        std::cout << node->asString() << std::endl;
    }

    std::cout << std::endl;

    return 0;
}
