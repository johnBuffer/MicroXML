#ifndef UTILS_HPP_INCLUDED
#define UTILS_HPP_INCLUDED

#include <string>
#include <vector>
#include <list>

#include "ParserXML.hpp"

bool found(size_t pos);
std::string purge(std::string& str);
void parseDeclaration(const std::string& str, Tag& tag);
Tag getNextTag(std::string& str, size_t start=0);

std::vector<std::string> split(const std::string& str, std::string sep);
std::vector<std::string> splitQuote(const std::string& str, char sep);

size_t findFirst(const std::string& str, char c, size_t start=0);

#endif // UTILS_HPP_INCLUDED
