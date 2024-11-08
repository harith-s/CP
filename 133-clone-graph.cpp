#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Node
{
public:
    int val;
    vector<Node *> neighbors;
    Node()
    {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val)
    {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors)
    {
        val = _val;
        neighbors = _neighbors;
    }
};
Node *cloneSubGraph(Node *node, map<int, Node *> &val_to_nodes)
{
    if (node == nullptr) return nullptr;

    Node *nodeCP = new Node(node->val);
    val_to_nodes[node->val] = nodeCP;
    for (auto adj : node->neighbors)
    {
        if (val_to_nodes.find(node->val) != val_to_nodes.end())
        {
            nodeCP->neighbors.push_back(val_to_nodes[adj->val]);
        }
        else
        {
            nodeCP->neighbors.push_back(cloneSubGraph(adj, val_to_nodes));
        }
    }
    return nodeCP;
}


Node *cloneGraph(Node *node)
{
    if (node == nullptr) return nullptr;
    
    Node *nodeCopy = new Node(node->val);

    map<int, Node *> val_to_nodes;

    val_to_nodes[node->val] = nodeCopy;

    for (auto adjnode : node->neighbors)
    {
        if (val_to_nodes.find(adjnode->val) != val_to_nodes.end())
        {
            nodeCopy->neighbors.push_back(val_to_nodes[adjnode->val]);
        }
        else
        {
            nodeCopy->neighbors.push_back(cloneSubGraph(adjnode, val_to_nodes));
        }
    }
    return nodeCopy;
}

