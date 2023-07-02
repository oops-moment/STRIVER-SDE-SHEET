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
     int height(TreeNode* root,int &maxm)
    {
        if(root==NULL)
        {
            return 0;
        }
        int lh=height(root->left,maxm);
        int rh=height(root->right,maxm);
        maxm=max(maxm,lh+rh);
        return max(lh,rh)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        // So at each node we need to actually calculate the lh+rh+1, and we need to take the maximum of this;
        int diam=INT_MIN;
        height(root,diam);
        return diam;
   
    }
};
