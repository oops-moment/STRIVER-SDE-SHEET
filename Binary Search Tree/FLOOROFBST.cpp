#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode {
       public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
void solve(int &ans, TreeNode<int>*root, int x)
{
    if(root==NULL)
    {
        return;
    }
    if(root->val==x)
    {
        ans=root->val;
        return;
    }
    if(root->val<x)
    {
        ans=root->val;
         solve(ans,root->right,x);
    }
    else
    {
        solve(ans,root->left,x);
    }

}
int floorInBST(TreeNode<int> * root, int x)
{
    // Write your code here.
    int ans=-1;
    solve(ans,root,x);
    return ans;
}
