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
    void addNode(std::string name);

    std::string           getName()     const;
    NodeXML&              operator[](std::string nodeName);
    NodeXML&              operator()(std::string path, std::string sep=".");
    std::vector<NodeXML*> getSubNodes();

    int asInt()            const;
    double asDouble()      const;
    std::string asString() const;

private:
    std::string _name;
    std::string _data;
    NodeXML*    _topNode;
    std::map<std::string, NodeXML> _subNodes;

    void print(std::string indent) const;
};

#endif // NODEXML_HPP_INCLUDED
