# MicroXML

## Description

MicroXML is a very lightweight (but strong:ant:) C++ dependence-free XML parsing librairy.

## How to use MicroXML

Giving the following XML file named books.xml (from https://msdn.microsoft.com/en-us/library/ms762271(v=vs.85).aspx): 

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

### Parse and explore data
MicroXML is able to read it and allows you to easily access its contents.

For instance, these few lines are all you need to retrieve all the authors mentioned in the file:

```c++
// First parse the file
NodeXML root = MicroXML::parse("books.xml");

// Access your data
NodeSet authors = root("catalog")("book")("author");

// View the data
for (auto node: authors)
{
    std::cout << node->asString() << std::endl;
}
```
Output:
```
Gambardella, Matthew
Ralls, Kim
Corets, Eva
```

Tags like author just stores data
```XML
<author>Ralls, Kim</author>
```
These data can be reached using the asString, asInt or asDouble methode exposed by NodeXML. It will return the choosen conversion of the string inside the tag. 
If int or double conversion fails, 0 will be returned.

### Alternative syntax
As you can see, access requests are simple but still tedious to write.
MicroXML provides an easier way to write this request using strings :point_right: inspired by the Scalpl project (https://github.com/ducdetronquito/scalpl) :+1: :+1: :+1:

```c++
// Same request using brackets
NodeSet authorsBis = root("catalog.book.author");

for (auto node : authorsBis)
{
    std::cout << node->asString() << std::endl;
}

// You can combine both
authorsBis = root("catalog.book")("author");

// You may also use your own separator depending on the punctuation you have already used
authorsBis = root("catalog/book/author", "/");

// Or change the default separator
MicroXML::setDefaultSeparator("/");

authorsBis = root("catalog/book/author");
```

### Attributes

Some tags have attributes:
```xml
<book id="bk101">
```
To access them you can use this synatx: ["attribute_name"]
```c++
NodeSet books = root("catalog/book");
for (auto node : books)
{
    std::cout << node["id"] << std::endl;
}
```
Output:
```
bk101
bk102
bk103
```