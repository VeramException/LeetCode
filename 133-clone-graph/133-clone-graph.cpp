/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution 
{
public:

    unordered_map<Node*, Node*> oldToNewMap;

    Node* cloneGraph(Node* node)
    {
        // edge case
        if (node == nullptr)
            return nullptr;

        // we already created a clone of this node.
        if (oldToNewMap.count(node) > 0)
            return oldToNewMap[node];

        // create a copy
        Node* copyNode = new Node(node->val);
        oldToNewMap[node] = copyNode;

        // for all neighbors of oldNode, create copy nodes and append them in 'copyNode->neighbors'
        for (Node* neighborNode: node->neighbors)
            copyNode->neighbors.push_back(cloneGraph(neighborNode));

        return copyNode;
    }
};