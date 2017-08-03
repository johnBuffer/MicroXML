#include <MicroXML/MicroXML.hpp>
#include <MicroXML/utils.hpp>
#include <iostream>
#include <fstream>
#include <sstream>

std::string MicroXML::_defaultSeparator = ".";

NodeXML MicroXML::parse(std::string filename)
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
                newNode->setAttr(tag._params);
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

void MicroXML::setDefaultSeparator(const std::string& separator)
{
    _defaultSeparator = separator;
}

const std::string& MicroXML::getDefaultSeparator()
{
    return _defaultSeparator;
}
