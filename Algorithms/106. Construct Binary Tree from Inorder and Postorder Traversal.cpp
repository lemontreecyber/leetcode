/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    static TreeNode* build(vector<int>& in, vector<int>& post, size_t len, size_t i0, size_t p0) {
        if (len == 0) return NULL;
        int root = post[p0 + len - 1];
        TreeNode* ans = new TreeNode(root);
        if (len == 1) return ans;
        size_t i = 0;
        for (; i < len; ++i)
            if (in[i0 + i] == root)
                break;
        ans->left = build(in, post, i, i0, p0);
        ans->right = build(in, post, len - i - 1, i0 + i + 1, p0 + i);
        return ans;
    }
   
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (inorder.size() == 0) return NULL;
        return build(inorder, postorder, inorder.size(), 0, 0);
    }
};

