#ifndef NODEXML_HPP_INCLUDED
#define NODEXML_HPP_INCLUDED

#include <string>
#include <map>
#include <vector>
#include <iostream>

class NodeXML
{
public:
    NodeXML();
    NodeXML(std::string name);

    void print() const;
    void setData(std::string data);
    void setParams(const std::map<std::string, std::string>& params);
    void addSubNode(std::string name);
    void setDefaultSeparator(std::string sep);

    std::string           getName()     const;
    NodeXML&              operator[](std::string nodeName);
    NodeXML&              operator()(std::string path);
    NodeXML&              operator()(std::string path, std::string sep);
    std::vector<NodeXML*> getSubNodes();
    std::string           get(const std::string& param) const;

    int asInt()            const;
    double asDouble()      const;
    std::string asString() const;

private:
    std::string _name;
    std::string _data;
    std::string _defaultSeparator;
    NodeXML*    _topNode;

    std::map<std::string, NodeXML> _subNodes;
    std::map<std::string, std::string> _params;

    void print(std::string indent) const;
};

#endif // NODEXML_HPP_INCLUDED
