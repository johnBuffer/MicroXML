#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include <vector>
#include <list>

#include "ParserXML.hpp"

#include "utils.hpp"

int main()
{
    NodeXML root = ParserXML::parse("test");

    root.print();

    /// Thx scalpl ;)
    std::cout << std::endl;
    std::cout << root["Zombie"]["Texture"]["Size"]["Width"].asInt() << std::endl;
    std::cout << root("Zombie.Texture")("Size.Width").asInt() << std::endl;
    std::cout << root("Zombie.Texture.Size")["Width"].asInt() << std::endl;
    std::cout << root("Zombie/Texture/Size", "/")["Width"].asInt() << std::endl;

    return 0;
}
