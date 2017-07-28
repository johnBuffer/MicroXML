#include "NodeSet.hpp"
#include "NodeXML.hpp"

#include "utils.hpp"

NodeXML* NodeSet::operator[](int i)
{
    return _set[i];
}

NodeSet NodeSet::find(const std::string& name)
{
    NodeSet result;

    for (NodeXML* node : _set)
    {
        if (node->getName().compare(name) == 0)
            result._set.push_back(node);
    }

    return result;
}

NodeSet NodeSet::operator[](const std::string& name)
{
    NodeSet result;

    for (NodeXML* node : _set)
    {
        result.addNodeSet(node->getNodeSet().find(name));
    }

    return result;
}

NodeSet NodeSet::operator()(std::string& path, const std::string& sep)
{
    std::vector<std::string> nodes = split(path, sep);

    NodeSet result;
    NodeSet* currentSet = this;
    for (const std::string& name : nodes)
    {
        result = (*currentSet)[name];
        currentSet = &result;
    }

    return result;
}

std::vector<NodeXML*>& NodeSet::operator()()
{
    return _set;
}

void NodeSet::addNode(NodeXML* node)
{
    _set.push_back(node);
}

void NodeSet::addNodeSet(const NodeSet& nodeSet)
{
    for (NodeXML* node : nodeSet._set)
    {
        _set.push_back(node);
    }
}

void NodeSet::print() const
{
    for (NodeXML* node : _set)
    {
        node->print();
    }
}
