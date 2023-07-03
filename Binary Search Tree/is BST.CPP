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
    bool check(TreeNode*root,long long int min, long long int max)
    {
        if(root==NULL)
        {
            return 1;
        }
        if(root->val<=min || root->val>=max)
        {
          return 0;
        }
        else
        {
             return check(root->left,min,root->val) && check(root->right,root->val,max);
        }

    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL || (root->left==NULL && root->right==NULL))
        {
            return 1;
        }
        long long int min=-2147483649;
        long long int max=2147483649;
        return check(root,min,max);
    }
};
