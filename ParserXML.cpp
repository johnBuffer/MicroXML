#include "ParserXML.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#include "utils.hpp"

std::string ParserXML::_defaultSeparator = ".";

NodeXML ParserXML::parse(std::string filename)
{
    NodeXML newNode("Root");

    std::ifstream infile(filename);
    if (!infile)
    {
        std::cerr << "[ERROR] cannot read file \"" << filename << "\"." << std::endl;
        return newNode;
    }

    std::list<NodeXML*> stack;
    stack.push_back(&newNode);

    std::string str, line;
    while (std::getline(infile, line)) {str += line;}
    str = purge(str);

    Tag tag = getNextTag(str);
    while (tag._isValid)
    {
        if (tag._type == CLOSE)
        {
            if (tag._name.compare(stack.back()->getName()) ==  0)
            {
                stack.back()->setData(tag._data);
                stack.pop_back();
            }
        }
        else if (tag._type != COMMENTED)
        {
            if (tag._type != SPECIAL)
            {
                NodeXML* newNode = stack.back()->addSubNode(tag._name);
                stack.push_back(newNode);
                newNode->setParams(tag._params);
            }
        }

        tag = getNextTag(str, tag._pos+1);
    }

    if (stack.size() > 1)
    {
        std::cout << "[WARNING] \"" << stack.back()->getName() << "\" not closed" << std::endl;
    }

    return newNode;
}

void ParserXML::setDefaultSeparator(const std::string& separator)
{
    _defaultSeparator = separator;
}

const std::string& ParserXML::getDefaultSeparator()
{
    return _defaultSeparator;
}
