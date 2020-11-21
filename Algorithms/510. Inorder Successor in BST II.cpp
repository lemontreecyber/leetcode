/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* parent;
};
*/

class Solution {
public:
    Node* inorderSuccessor(Node* node) {
        if (!node) return NULL;
        if (node->right) {
            node = node->right;
            while (node->left) node = node->left;
            return node;
        }
        if (node->parent) {
            while (node->parent->right == node) {
                node = node->parent;
                if (!node->parent) return NULL;
            }
            return node->parent;
        }
        return NULL;
    }
};
