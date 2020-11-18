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
    static TreeNode* build(vector<int>& pre, vector<int>& in, size_t len, size_t p0, size_t i0) {
        if (len == 0) return NULL;
        int prep0 = pre[p0];
        TreeNode* ans = new TreeNode(prep0);
        if (len == 1) return ans;
        size_t i = 0;
        for (; i < len; ++i)
            if (in[i0 + i] == prep0)
                break;
        ans->left = build(pre, in, i, p0 + 1, i0);
        ans->right = build(pre, in, len - i - 1, p0 + i + 1, i0 + i + 1);
        return ans;
    }
   
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0) return NULL;
        return build(preorder, inorder, preorder.size(), 0, 0);
    }
};
