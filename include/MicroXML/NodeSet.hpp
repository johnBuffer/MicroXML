#ifndef NODESET_HPP_INCLUDED
#define NODESET_HPP_INCLUDED

#include <MicroXML/utils.hpp>
#include <string>
#include <vector>

/* Stores a set of nodes. It is possible to recursively
request on sets */

class NodeXML;
class NodeSet;

/// Stores a pointer to a NodeXML and exposes it's methods
struct NodePtr
{
    NodePtr(NodeXML& node) :
        _node(&node) {}

    NodeSet     operator()(const std::string& name);
    std::string operator[](const std::string& attr);
    NodeXML&    operator*() {return *_node;}

    NodeXML*       operator->() {return _node;}
    const NodeXML* operator->() const {return _node;}

    NodeXML* _node;
};

class NodeSet
{
public:
    /// Return the i th element
    NodeXML& operator[](int i);

    /// Return an attribute of all the elements
    StrVec operator[](const std::string& attr);

    /// Exploration
    NodeSet operator()(const std::string& path);
    NodeSet operator()(const std::string& path, const std::string& sep);
    NodeSet find(const std::string& name);

    /// Return all nodes
    std::vector<NodePtr>& operator()();

    /// Iterator handling
    std::vector<NodePtr>::iterator begin();
    std::vector<NodePtr>::iterator end();
    std::vector<NodePtr>::const_iterator begin() const;
    std::vector<NodePtr>::const_iterator end()   const;

    /// Adds a node
    void addNode(NodeXML* node);

    /// Adds all nodes of an other NodeSet
    void addNodeSet(const NodeSet& nodeSet);

    /// Displays all nodes
    void print() const;

private:
    std::vector<NodePtr> _set;
    NodeSet _findNodesByName(const std::string& name);
};

#endif // NODESET_HPP_INCLUDED
