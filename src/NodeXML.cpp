#include <MicroXML/NodeXML.hpp>
#include <MicroXML/MicroXML.hpp>
#include <iostream>

NodeXML::NodeXML() :
    _name(""),
    _data(""),
    _topNode(nullptr)
{}

NodeXML::NodeXML(std::string name) :
    _name(name),
    _data(""),
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
    NodeXML* newNode = new NodeXML(name);
    _subNodes.addNode(newNode);
    newNode->_topNode = this;

    return &(*_subNodes._set.back());
}

std::string NodeXML::operator[](std::string attr)
{
    return get(attr);
}

NodeSet NodeXML::operator()(std::string path)
{
    NodeSet result;
    result.addNode(this);
    return result(path, MicroXML::getDefaultSeparator());
}

NodeSet NodeXML::operator()(std::string path, const std::string& sep)
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
        node->print(indent+"  ");

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

std::string NodeXML::get(const std::string& attr) const
{
    if (_params.find(attr) != _params.end())
        return _params.at(attr);
    return "";
}

std::string NodeXML::asString() const
{
    return _data;
}
