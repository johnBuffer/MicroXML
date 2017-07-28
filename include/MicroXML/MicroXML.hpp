#ifndef MicroXML_H_INCLUDED
#define MicroXML_H_INCLUDED

#include "NodeXML.hpp"

class MicroXML
{
public:
    static NodeXML parse(std::string filename);
    static void setDefaultSeparator(const std::string& separator);

    static const std::string& getDefaultSeparator();

private:
    static std::string _defaultSeparator;
};

#endif // MicroXML_H_INCLUDED
