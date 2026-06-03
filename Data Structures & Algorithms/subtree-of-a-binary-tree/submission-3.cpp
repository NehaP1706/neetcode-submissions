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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q)
        {
            return true;
        }
        
        if (p && q && p->val != q->val)
        {
            return false;
        }
        
        if (!p && q || p && !q)
        {
            return false;
        }

        if (!p->left && !p->right && !q->left && !q->right)
        {
            return true;
        }

        if (p->left && q->left && p->left->val != q->left->val)
        {
            return false;
        }

        if (p->right && q->right && p->right->val != q->right->val)
        {
            return false;
        }

        if (p->left && !q->left || !p->left && q->left)
        {
            return false;
        }

        if (p->right && !q->right || !p->right && q->right)
        {
            return false;
        }

        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (!root)
            return false;

        if (isSameTree(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};
