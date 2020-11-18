/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    static TreeNode* iobfs(TreeNode* root, int val, bool& found) {
        // returns null if the last in iobfs(root) is val
        TreeNode* ans = NULL;
        if (root->left) {
            ans = iobfs(root->left, val, found);
            if (found)
                return ans ? ans : root;
        }
        if (root->val == val) {
            found = true;
            if (!root->right) return NULL;
            TreeNode* r = root->right;
            while (r->left) r = r->left;
            return r;
        }
        if (root->right) {
            ans = iobfs(root->right, val, found);
            if (found)
                return ans;
        }
        return NULL;
    }
   
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (!root || !p) return NULL;
        bool found = false;
        return iobfs(root, p->val, found);
    }
};

