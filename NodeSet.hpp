#ifndef NODESET_HPP_INCLUDED
#define NODESET_HPP_INCLUDED

#include <string>
#include <vector>

class NodeXML;

class NodeSet
{
public:

    NodeXML* operator[](int i);
    NodeSet  operator[](const std::string& name);
    NodeSet  operator()(std::string& path, std::string& sep);
    NodeSet  find(const std::string& name);

    std::vector<NodeXML*>& operator()();

    void addNode(NodeXML* node);
    void addNodeSet(const NodeSet& nodeSet);
    void print() const;

    std::vector<NodeXML*> _set;
};

#endif // NODESET_HPP_INCLUDED
