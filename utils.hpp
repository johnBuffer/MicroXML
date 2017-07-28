#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <vector>
#include <list>
#include <map>

typedef std::vector<std::string>           StrVec;
typedef std::map<std::string, std::string> StrMap;

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

bool found(size_t pos);
std::string purge(std::string& str);
void parseDeclaration(const std::string& str, Tag& tag);
Tag getNextTag(std::string& str, size_t start=0);

StrVec split(const std::string& str, std::string sep);
StrVec splitQuote(const std::string& str, char sep);

size_t findFirst(const std::string& str, char c, size_t start=0);

#endif // UTILS_HPP_INCLUDED
