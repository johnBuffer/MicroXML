#ifndef NODESET_HPP_INCLUDED
#define NODESET_HPP_INCLUDED

#include <MicroXML/utils.hpp>
#include <string>
#include <vector>

class NodeXML;
class NodeSet;

struct NodePtr
{
    NodePtr(NodeXML& node) :
        _node(&node) {}

    NodeSet     operator()(const std::string& name);
    NodeXML&    operator*()  {return *_node;}
    std::string operator[](const std::string& attr);

    NodeXML*       operator->() {return _node;}
    const NodeXML* operator->() const {return _node;}

    NodeXML* _node;
};

class NodeSet
{
public:

    NodeXML& operator[](int i);
    StrVec   operator[](const std::string& attr);
    NodeSet  operator()(const std::string& path);
    NodeSet  operator()(const std::string& path, const std::string& sep);
    NodeSet  find(const std::string& name);

    std::vector<NodePtr>& operator()();
    std::vector<NodePtr>::iterator begin();
    std::vector<NodePtr>::iterator end();

    void addNode(NodeXML* node);
    void addNodeSet(const NodeSet& nodeSet);
    void print() const;

    std::vector<NodePtr> _set;

private:
    NodeSet _findNodesByName(const std::string& name);
};

#endif // NODESET_HPP_INCLUDED
