#include "ParserXML.hpp"

int main()
{
    NodeXML root = ParserXML::parse("test");

    root.print();

    /// Thx scalpl ;)
    std::cout << std::endl;
    std::cout << root["Zombie"]["Texture"]["Size"]["Width"].asInt() << std::endl;
    std::cout << root("Zombie.Texture.Size.Width").asInt() << std::endl;
    std::cout << root("Zombie.Texture")("Size.Width").asInt() << std::endl;
    std::cout << root("Zombie.Texture.Size")["Width"].asInt() << std::endl;
    std::cout << root("Zombie/Texture/Size", "/")["Width"].asInt() << std::endl;

    root.setDefaultSeparator("/");
    std::cout << root("Zombie/Texture/Size/Width").asInt() << std::endl;

    return 0;
}
