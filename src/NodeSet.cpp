#include <MicroXML/MicroXML.hpp>
#include <MicroXML/NodeSet.hpp>
#include <MicroXML/NodeXML.hpp>

NodeSet NodePtr::operator()(const std::string& name)
{
     return (*_node)(name);
}

std::string NodePtr::operator[](const std::string& attr)
{
     return (*_node)[attr];
}

NodeXML& NodeSet::operator[](int i)
{
    return *(_set[i]._node);
}

NodeSet NodeSet::find(const std::string& name)
{
    NodeSet result;

    for (NodePtr& node : _set)
    {
        if (node->getName().compare(name) == 0)
            result._set.push_back(node);
    }

    return result;
}

StrVec NodeSet::operator[](const std::string& attr)
{
    StrVec result;

    for (NodePtr& node : _set)
    {
        result.push_back(node[attr]);
    }

    return result;
}

NodeSet NodeSet::_findNodesByName(const std::string& name)
{
    NodeSet result;

    for (NodePtr node : _set)
    {
        result.addNodeSet(node->getNodeSet().find(name));
    }

    return result;
}

NodeSet NodeSet::operator()(const std::string& path)
{
    return this->operator()(path, MicroXML::getDefaultSeparator());
}

NodeSet NodeSet::operator()(const std::string& path, const std::string& sep)
{
    std::vector<std::string> nodes = split(path, sep);

    NodeSet result;
    NodeSet* currentSet = this;
    for (const std::string& name : nodes)
    {
        result = currentSet->_findNodesByName(name);
        currentSet = &result;
    }

    return result;
}

std::vector<NodePtr>& NodeSet::operator()()
{
    return _set;
}

std::vector<NodePtr>::iterator NodeSet::begin()
{
    return _set.begin();
}

std::vector<NodePtr>::iterator NodeSet::end()
{
    return _set.end();
}

std::vector<NodePtr>::const_iterator NodeSet::begin() const
{
    return _set.begin();
}

std::vector<NodePtr>::const_iterator NodeSet::end() const
{
    return _set.end();
}

void NodeSet::addNode(NodeXML* node)
{
    _set.push_back(NodePtr(*node));
}

void NodeSet::addNodeSet(const NodeSet& nodeSet)
{
    for (NodePtr node : nodeSet._set)
    {
        _set.push_back(node);
    }
}

void NodeSet::print() const
{
    for (NodePtr node : _set)
    {
        node->print();
    }
}
