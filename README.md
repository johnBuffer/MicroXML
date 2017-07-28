# MicroXML

## Description

MicroXML is a very lightweight (but strong :ant:) C++ dependence-free XML parsing librairy.

## Exemple

Giving the following XML file named test : 

```xml
<Zombie>
  <Texture>
    <Filename>
      "zombie_texture.png"
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

For instance, these few lines are all you need to retrieve the width of the of the Zombie's texture :

```c++
// First parse the file
NodeXML root = ParserXML::parse("test");

// Access your data as an int
int width = root["Zombie"]["Texture"]["Size"]["Width"].asInt();
```

As you can see, access requests are simple but still tedious to write.
MicroXML provides an easier way to write this request using strings -> based on the Scalpl project (https://github.com/ducdetronquito/scalpl) :+1: :+1: :+1:

```c++
int width, heigth;
// Same request using brackets
width = root("Zombie.Texture.Size.Width").asInt(); 

// You can combine both
width = root("Zombie.Texture.Size")["Width"].asInt();
width = root("Zombie.Texture")("Size.Width").asInt();

// You may also use your own separator depending on the punctuation you have already used
width = root("Zombie/Texture/Size", "/")["Width"].asInt();

// Or change the default separator
root.setDefaultSeparator("/");

width  = root("Zombie/Texture/Size/Width").asInt();
height = root("Zombie/Texture/Size/Height").asInt();

std::string filename = root("Zombie/Texture/Filename").asString();
```

## Limitations
- [x] Currently MicroXML doesn't support attributes in tag declaration.
- [ ] MicroXML doesn't issue a warning in case of invalid request, it just crashes :poop: