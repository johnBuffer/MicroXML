#ifndef PARSERXML_H_INCLUDED
#define PARSERXML_H_INCLUDED

#include "NodeXML.hpp"

class ParserXML
{
public:
    static NodeXML parse(std::string filename);
    static void setDefaultSeparator(const std::string& separator);

    static const std::string& getDefaultSeparator();

private:
    static std::string _defaultSeparator;
};

#endif // PARSERXML_H_INCLUDED
