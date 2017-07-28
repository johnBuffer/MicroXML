#include "ParserXML.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

#include "utils.hpp"

NodeXML ParserXML::parse(std::string filename)
{
    NodeXML newNode("Root");

    std::ifstream infile(filename);
    std::list<NodeXML*> stack;

    std::string str, line;
    while (std::getline(infile, line)) {str += line;}
    str = purge(str);

    stack.push_back(&newNode);
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
        else
        {
            NodeXML* newNode = stack.back()->addSubNode(tag._name);
            stack.push_back(newNode);
            newNode->setParams(tag._params);
        }

        tag = getNextTag(str, tag._pos+1);
    }

    return newNode;
}
