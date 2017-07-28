#ifndef NODEXML_HPP_INCLUDED
#define NODEXML_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>
#include <list>
#include <iostream>

#include "NodeSet.hpp"

class NodeXML
{
public:
    NodeXML();
    NodeXML(std::string name);

    void print() const;
    void setData(std::string data);
    void setParams(const std::map<std::string, std::string>& params);
    void setDefaultSeparator(std::string sep);

    NodeXML*    addSubNode(std::string name);
    NodeSet     operator[](std::string nodeName);
    NodeSet     operator()(std::string path);
    NodeSet     operator()(std::string path, std::string sep);
    std::string getName() const;
    std::string get(const std::string& param) const;
    NodeSet&    getNodeSet();

    int asInt()            const;
    double asDouble()      const;
    std::string asString() const;

private:
    std::string _name;
    std::string _data;
    std::string _defaultSeparator;
    NodeXML*    _topNode;

    NodeSet _subNodes;
    std::map<std::string, std::string> _params;

    void print(std::string indent) const;
};

#endif // NODEXML_HPP_INCLUDED
