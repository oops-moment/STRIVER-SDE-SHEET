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
    int helper(TreeNode*root,int &finalAnswer)
    {
        if(root==NULL)
        {
            return 0 ;
        }

        int lh=helper(root->left,finalAnswer);
        int rh=helper(root->right,finalAnswer);
        int tempsum=root->val;
        if(lh>=0)
        {
            tempsum+=lh;
        }
        if(rh>=0)
        {
            tempsum+=rh;
        }
        finalAnswer=max(finalAnswer,tempsum);

        if(max(lh,rh)>=0)
        {
            return root->val+max(lh,rh);
        }
        else
        {
            return root->val;
        }

    }
    int maxPathSum(TreeNode* root) {
        // we can do this question recursively
        int finalAnswer=INT_MIN;
        helper(root,finalAnswer);
        return finalAnswer;        
    }
};
