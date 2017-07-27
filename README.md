# MicroXML

## Description

MicroXML is a very lightweight C++ dependence-free XML parsing librairy.

## Exemple

Giving the following XML file named test : 

```xml
<Zombie>
  <Texture>
    <Filename>
    "zombie_texture.png  et plus encore"
  </Filename>
    <Size>
      <Width>800</Width>
      <Height>650</Height>
    </Size>
  </Texture>
</Zombie>
<Hunter>
  <Texture>
    <Filename>
    </Filename>
    <Size>
      <Width>1500</Width>
      <Height>800</Height>
    </Size>
  </Texture>
</Hunter>
```

MicroXML is able to read it and allows you to easily access its contents.

For exemple, to retrieve the height of the Zombie's texture you just need these lines :

```c++
// First parse the file
NodeXML root = ParserXML::parse("test");

// Access your data as an int
int height = root["Zombie"]["Texture"]["Size"]["Width"].asInt();
```

As you can see, access requests are simple but still long to write.
MicroXML provides an easier way to write this request using strings based on the Scalpl project (https://github.com/ducdetronquito/scalpl) :

```c++
// Same request
int height = root("Zombie.Texture.Size.Width").asInt(); 

// You can combine both
std::cout << root("Zombie.Texture")("Size.Width").asInt() << std::endl;
std::cout << root("Zombie.Texture.Size")["Width"].asInt() << std::endl;

// And choose your own separator dependng on your needs
std::cout << root("Zombie/Texture/Size", "/")["Width"].asInt() << std::endl;
```