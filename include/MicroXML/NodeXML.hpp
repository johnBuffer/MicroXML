#ifndef NODEXML_HPP_INCLUDED
#define NODEXML_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>

#include "NodeSet.hpp"
#include "utils.hpp"

class NodeXML
{
public:
    NodeXML();
    NodeXML(std::string name);

    void print() const;
    void setData(std::string data);
    void setParams(const StrMap& params);

    NodeSet     operator()(std::string path);
    NodeSet     operator()(std::string path, const std::string& sep);
    NodeXML*    addSubNode(std::string name);
    NodeSet&    getNodeSet();

    std::string operator[](std::string attr);
    std::string  getName() const;
    std::string  get(const std::string& param) const;

    int         asInt()    const;
    double      asDouble() const;
    std::string asString() const;

private:
    std::string _name;
    std::string _data;
    NodeXML*    _topNode;

    NodeSet _subNodes;
    StrMap  _params;

    void print(std::string indent) const;
};

#endif // NODEXML_HPP_INCLUDED
