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

class Solution {
    static Node* make_new(vector<Node*>& new_nodes, Node* mould) {
        if (mould->val >= new_nodes.size())
            new_nodes.resize(mould->val + 1);
        if (new_nodes[mould->val])
            return new_nodes[mould->val];
        Node* ans = new Node(mould->val);
        new_nodes[mould->val] = ans;
        return ans;
    }
   
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        vector<Node*> new_nodes;
        Node* new_root = make_new(new_nodes, node);
        queue<pair<Node*, Node*>> bfs;
        bfs.emplace(new_root, node);
        while (!bfs.empty()) {
            auto [new_node, old_node] = bfs.front();
            bfs.pop();
            for (Node* p : old_node->neighbors) {
                bool const visited = (p->val < new_nodes.size()) && (new_nodes[p->val] != NULL);
                Node* const np = make_new(new_nodes, p);
                new_node->neighbors.push_back(np);
                if (!visited) bfs.emplace(np, p);
            }
        }
        return new_root;
    }
};

