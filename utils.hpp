#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <vector>
#include <list>

#include "ParserXML.hpp"

bool found(size_t pos);
std::string purge(std::string& str);
void parseDeclaration(const std::string& str, Tag& tag);
Tag getNextTag(std::string& str);
std::vector<std::string> split(const std::string& str, std::string sep);
std::vector<std::string> splitQuote(const std::string& str, char sep);


#endif // UTILS_HPP_INCLUDED
