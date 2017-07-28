# MicroXML

## Description

MicroXML is a very lightweight (but strong :ant:) C++ dependence-free XML parsing librairy.

## Exemple

Giving the following XML file named books.xml (from https://msdn.microsoft.com/en-us/library/ms762271(v=vs.85).aspx) : 

```xml
<?xml version="1.0" encoding="UTF-8"?>
<catalog>
   <book id="bk101">
      <author>Gambardella, Matthew</author>
      <title>XML Developer's Guide</title>
      <genre>Computer</genre>
      <price>44.95</price>
      <publish_date>2000-10-01</publish_date>
      <description>An in-depth look at creating applications 
      with XML.</description>
   </book>
   <book id="bk102">
      <author>Ralls, Kim</author>
      <title>Midnight Rain</title>
      <genre>Fantasy</genre>
      <price>5.95</price>
      <publish_date>2000-12-16</publish_date>
      <description>A former architect battles corporate zombies, 
      an evil sorceress, and her own childhood to become queen 
      of the world.</description>
   </book>
   <book id="bk103">
      <author>Corets, Eva</author>
      <title>Maeve Ascendant</title>
      <genre>Fantasy</genre>
      <price>5.95</price>
      <publish_date>2000-11-17</publish_date>
      <description>After the collapse of a nanotechnology 
      society in England, the young survivors lay the 
      foundation for a new society.</description>
   </book>
</catalog>
```

MicroXML is able to read it and allows you to easily access its contents.

For instance, these few lines are all you need to retrieve all the authors mentioned in the file :

```c++
// First parse the file
NodeXML root = ParserXML::parse("books.xml");

// Access your data
NodeSet authors = root["catalog"]["book"]["author"];

// View the data
for (auto node : authors)
{
	std::cout << node->asString() << std::endl;
}
```

```
Gambardella, Matthew
Ralls, Kim
Corets, Eva
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
