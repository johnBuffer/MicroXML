#ifndef PARSERXML_H_INCLUDED
#define PARSERXML_H_INCLUDED

#include "NodeXML.hpp"

class ParserXML
{
public:
    static NodeXML parse(std::string filename);
};

#endif // PARSERXML_H_INCLUDED
