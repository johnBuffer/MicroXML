#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <vector>
#include <list>
#include <map>

typedef std::vector<std::string>           StrVec;
typedef std::map<std::string, std::string> StrMap;

const char XML_SLASH     = '/';
const char XML_TAG_START = '<';
const char XML_TAG_END   = '>';

const std::string XML_DOCUMENT_HEADER = "?xml";
const std::string XML_COMMENT_START   = "!--";
const std::string XML_COMMENT_END     = "-->";

enum TagType
{
    OPEN,
    CLOSE,
    SPECIAL,
    COMMENTED,
    AUTO_CLOSED
};

struct Tag
{
    std::string _name;
    std::string _data;
    StrMap      _params;

    TagType _type;
    size_t  _pos;
    bool    _isValid;
};

Tag         getNextTag(std::string& str, size_t start=0);
int         strToInt(const std::string& str);
double      strToDouble(const std::string& str);
bool        found(size_t pos);
void        parseDeclaration(const std::string& str, Tag& tag);
StrVec      split(const std::string& str, std::string sep);
StrVec      splitQuote(const std::string& str, char sep);
size_t      findFirst(const std::string& str, char c, size_t start=0);
std::string purge(std::string& str);


#endif // UTILS_HPP_INCLUDED
