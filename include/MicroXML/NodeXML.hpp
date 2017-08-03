#ifndef NODEXML_HPP_INCLUDED
#define NODEXML_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>

#include "NodeSet.hpp"
#include "utils.hpp"

/* Stores all the XML elements - surrounded by tags */

class NodeXML
{
public:
    /// Constructors
    NodeXML();
    NodeXML(std::string name);

    /// Shows sub nodes
    void print() const;

    /// Changes node's data
    void setData(const std::string& data);

    /// Changes node's attributes
    void setAttr(const StrMap& attr);

    /// Different exploration methods
    NodeSet operator()(const std::string& path);
    NodeSet operator()(const std::string& path, const std::string& sep);

    /// Creates and adds a sub node
    NodeXML* addSubNode(const std::string& name);

    /// Returns all sub nodes
    NodeSet& getNodeSet();

    /// Access an attribute by its name
    std::string operator[](const std::string& attr);
    std::string get(const std::string& attr) const;

    /// Return node's name
    std::string getName() const;

    /// Return node's data casted into desired type
    int         asInt()    const;
    double      asDouble() const;
    std::string asString() const;

    void saveToFile(const std::string& filename) const;

private:
    /// Node's name
    std::string _name;
    /// Node's data
    std::string _data;
    /// Parent node
    NodeXML* _topNode;
    /// Sub nodes
    NodeSet _subNodes;
    /// Attributes
    StrMap  _attr;

    /// Recursive call of print, for indent
    void _print(std::string indent) const;

    void _saveToFile(std::ofstream& file, const std::string indent) const;
};

#endif // NODEXML_HPP_INCLUDED
