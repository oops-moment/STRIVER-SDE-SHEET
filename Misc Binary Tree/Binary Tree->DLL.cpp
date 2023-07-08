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
    void preorder(TreeNode*root,vector<TreeNode*>&preorderT)
    {
        if(root==NULL)
        {
            return;
        }
        preorderT.push_back(root);
        preorder(root->left,preorderT);
        preorder(root->right,preorderT);
    }
    void flatten(TreeNode* root) {
        //lets us store the preorder traversal into into some array , the use that array to find the final answer
        if(root==NULL)
        {
            return;
        }
        vector<TreeNode*>preorderT;
        preorder(root,preorderT);
        int n=preorderT.size();
        for(int i=0;i<n-1;i++)
        {
            preorderT[i]->right=preorderT[i+1];
            preorderT[i]->left=NULL;
        }
        preorderT[n-1]->right=NULL;
        preorderT[n-1]->left=NULL;
    }
};
