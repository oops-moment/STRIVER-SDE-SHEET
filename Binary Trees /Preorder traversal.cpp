 void preorder(vector<int>&finalAnswer,TreeNode* root)
    {
        if(root==NULL)
        {
            return;
        }
        finalAnswer.push_back(root->val);
        preorder(finalAnswer,root->left);
        preorder(finalAnswer, root->right);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int>finalAnswer; 
       preorder(finalAnswer,root);
       return finalAnswer;
    }
