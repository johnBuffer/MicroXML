#ifndef PARSERXML_H_INCLUDED
#define PARSERXML_H_INCLUDED

#include "NodeXML.hpp"

enum TagType
{
    OPEN,
    CLOSE,
    AUTO_CLOSED
};

struct Tag
{
    std::string _name;
    std::string _params;
    std::string _data;

    TagType _type;
    bool    _isValid;
};

class ParserXML
{
public:
    static NodeXML parse(std::string filename);
};

#endif // PARSERXML_H_INCLUDED
