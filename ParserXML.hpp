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
    std::string _data;
    std::map<std::string, std::string> _params;

    TagType _type;
    bool    _isValid;
};

class ParserXML
{
public:
    static NodeXML parse(std::string filename);

private:
    static void parseParams(std::string params, NodeXML& node);
};

#endif // PARSERXML_H_INCLUDED
