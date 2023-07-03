#include <bits/stdc++.h> 
/************************************************************

    Following is the Tree node structure
	
	template <typename T>
    class TreeNode 
    {
        public : 
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T val) 
        {
            this -> val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
 long long int helper(TreeNode<int>*root,long long int &finalAnswer)
    {
        if(root==NULL)
        {
            return -1e8 ;
        }
        if(root->left==NULL && root->right==NULL)
        {
            return root->val;
        }
        long long int lh=helper(root->left,finalAnswer);
        long long int rh=helper(root->right,finalAnswer);
       if(lh==-1e8 || rh==-1e8)
       {
          return( root->val+max(lh,rh)); 
       }
        finalAnswer=max(finalAnswer,root->val+lh+rh);
        return max(lh,rh)+root->val;
       
    }
long long int findMaxSumPath(TreeNode<int> *root)
{
    // Write your code here.
    if(root==NULL)
    {
        return -1;
    }      
    long long int ans=-1;
    helper(root,ans);
    return ans;
}

