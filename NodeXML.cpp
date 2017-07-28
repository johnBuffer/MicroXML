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

NodeXML* NodeXML::addSubNode(std::string name)
{
    _subNodes._set.push_back(new NodeXML(name));
    _subNodes._set.back()->_topNode = this;

    return _subNodes._set.back();
}

void NodeXML::setDefaultSeparator(std::string sep)
{
    _defaultSeparator = sep;
}

NodeSet NodeXML::operator[](std::string name)
{
    NodeSet result;
    result.addNode(this);
    return result[name];
}

NodeSet NodeXML::operator()(std::string path)
{
    NodeSet result;
    result.addNode(this);
    return result(path, _defaultSeparator);
}

NodeSet NodeXML::operator()(std::string path, std::string sep)
{
    NodeSet result;
    result.addNode(this);
    return result(path, sep);
}

std::string NodeXML::getName() const
{
    return _name;
}

NodeSet& NodeXML::getNodeSet()
{
    return _subNodes;
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

    for (auto& node : _subNodes._set)
    {
        node->print(indent+"  ");
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
