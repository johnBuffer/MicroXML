#include "NodeXML.hpp"
#include <iostream>
#include "utils.hpp"

NodeXML::NodeXML() :
    _name(""),
    _data(""),
    _defaultSeparator("."),
    _topNode(nullptr)
{}

NodeXML::NodeXML(std::string name) :
    _name(name),
    _data(""),
    _defaultSeparator("."),
    _topNode(nullptr)
{}

void NodeXML::setData(std::string data)
{
    _data = data;
}

void NodeXML::setParams(const std::map<std::string, std::string>& params)
{
    _params = params;
}

void NodeXML::addSubNode(std::string name)
{
    _subNodes[name] = NodeXML(name);
    _subNodes[name]._topNode = this;
}

void NodeXML::setDefaultSeparator(std::string sep)
{
    _defaultSeparator = sep;
}

NodeXML& NodeXML::operator[](std::string name)
{
    return _subNodes[name];
}

NodeXML& NodeXML::operator()(std::string path)
{
    return this->operator()(path, _defaultSeparator);
}

NodeXML& NodeXML::operator()(std::string path, std::string sep)
{
    std::vector<std::string> nodes = split(path, sep);

    NodeXML* currentNode = this;
    for (const std::string& name : nodes)
    {
        currentNode = &(*currentNode)[name];
    }

    return *currentNode;
}

std::string NodeXML::getName() const
{
    return _name;
}

std::vector<NodeXML*> NodeXML::getSubNodes()
{
    std::vector<NodeXML*> result;

    for (auto& node : _subNodes)
        result.push_back(&node.second);

    return result;
}

void NodeXML::print() const
{
    print("");
}

void NodeXML::print(std::string indent) const
{
    std::cout << indent << "+"+_name;
    if (!_data.empty())
        std::cout << " -> " << _data;
    std::cout << std::endl;

    for (auto& node : _subNodes)
    {
        node.second.print(indent+"  ");
    }
    std::cout << indent << "-"+_name << std::endl;
}

int NodeXML::asInt() const
{
    return std::stoi(_data);
}

double NodeXML::asDouble() const
{
    return std::stod(_data);
}

std::string NodeXML::get(const std::string& param) const
{
    return _params.at(param);
}

std::string NodeXML::asString() const
{
    return _data;
}
