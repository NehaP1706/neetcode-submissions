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
    void solve(vector<int>& res, TreeNode* root)
    {
        if (!root)
        {
            return;
        }

        solve(res, root->left);

        res.push_back(root->val);

        solve(res, root->right);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;

        solve(res, root);

        return res;
    }
};