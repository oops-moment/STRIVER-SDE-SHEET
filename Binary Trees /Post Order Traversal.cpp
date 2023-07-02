// LEFT RIGHT ROOT
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
 void solve(TreeNode*root,vector<int>&ans)
{
    // left right root
    if(root && root->left!=NULL)
    {
        solve(root->left,ans);
    }
    if(root && root->right!=NULL)
    {
        solve(root->right,ans); 
    }
    if(root)
    {
        ans.push_back(root->val);
    }
}
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        solve(root,ans);
        return ans;
    }
};
