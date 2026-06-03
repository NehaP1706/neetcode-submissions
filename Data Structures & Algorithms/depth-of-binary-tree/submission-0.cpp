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
public:
    void solve(TreeNode* root, int& ans, int depth)
    {
        if (!root)
        {
            return;
        }

        if (!root->left && !root->right)
        {
            ans = max(ans, depth);
        }

        solve(root->left, ans, depth+1);
        solve(root->right, ans, depth+1);
    }
    int maxDepth(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        
        int ans = 1;
        int depth = 1;

        solve(root, ans, depth);

        return ans;
    }
};
