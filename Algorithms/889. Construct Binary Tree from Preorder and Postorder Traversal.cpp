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
    static TreeNode* build(vector<int>& pre, vector<int>& post, size_t len, size_t pre0, size_t post0) {
        if (len == 0) return NULL;
        TreeNode* ans = new TreeNode(pre[pre0]);
        if (len == 1) return ans;
        int left = pre[pre0 + 1];
        size_t i = 0;
        for (; i < len; ++i)
            if (post[post0 + i] == left)
                break;
        ans->left = build(pre, post, i + 1, pre0 + 1, post0);
        ans->right = build(pre, post, len - i - 2, pre0 + i + 2, post0 + i + 1);
        return ans;
    }
   
public:
    TreeNode* constructFromPrePost(vector<int>& pre, vector<int>& post) {
        return build(pre, post, pre.size(), 0, 0);
    }
};
