/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    Node* cloneTree(Node* root) {
        if (!root) return NULL;
        Node* nroot = new Node(root->val);
        queue<pair<Node*, Node*>> bfs;
        bfs.emplace(nroot, root);
        while (!bfs.empty()) {
            auto [nnode, node] = bfs.front();
            bfs.pop();
            for (Node* p : node->children) {
                Node* np = new Node(p->val);
                nnode->children.push_back(np);
                bfs.emplace(np, p);
            }
        }
        return nroot;
    }
};
