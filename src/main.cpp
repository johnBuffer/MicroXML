#include <MicroXML/MicroXML.hpp>

int main()
{
    NodeXML root = MicroXML::parse("test.xml");

    NodeSet genres    = root["catalog"]["book"]["genre"];
    NodeSet genresBis = root("catalog.book.genre");

    for (auto node : genres)
    {
        std::cout << node->asString() << std::endl;
    }

    std::cout << std::endl;

    for (auto node : genresBis)
    {
        std::cout << node->asString() << std::endl;
    }

    return 0;
}
