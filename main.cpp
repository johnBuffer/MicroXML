#include "ParserXML.hpp"
#include "utils.hpp"

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
    std::cout << root("Zombie/Texture").get("quality") << std::endl;
    std::cout << root("Zombie/Texture").get("format") << std::endl;



    /*std::string test = "    ok ceci     est un    \"test de ouf\"";
    auto v = splitQuote(test, ' ');

    for (auto s : v)
        std::cout << "|" << s << "|" << std::endl;*/

    return 0;
}
