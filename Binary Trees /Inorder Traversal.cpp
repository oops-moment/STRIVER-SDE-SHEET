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
    void inorder(vector<int>&finalAnswer,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        if(root->left!=NULL)
        {
            inorder(finalAnswer,root->left);
        }
        if(root)
        {
            finalAnswer.push_back(root->val);
        }
        if(root->right!=NULL)
        {
            inorder(finalAnswer, root->right);
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int>finalAnswer;
        inorder(finalAnswer,root);
        return finalAnswer;
    }
};
