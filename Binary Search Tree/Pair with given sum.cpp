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
    int ans=0;
    void inorder(TreeNode*root, int k, map<int,int>&mp)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left)
        {
            inorder(root->left,k,mp);
        }
        if(root)
        {
            if(mp[k-root->val]==1)
            {
                ans=1;
                return;
            }
            else
            {
                mp[root->val]=1;
            }
        }
        if(root->right)
        {
            inorder(root->right,k, mp);
        }
        
    }
    bool findTarget(TreeNode* root, int k) {
        map<int,int>mp;
        inorder(root,k,mp);
        return ans;
    }
};
