#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:

    class BinaryTreeNode
    {
    public :
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


************************************************************/
void preorder(BinaryTreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
        ans.push_back(root->data);

    preorder(root->left,ans);
    preorder(root->right,ans);
}
void postorder(BinaryTreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    postorder(root->left,ans);
    postorder(root->right,ans);
        ans.push_back(root->data);

}
void inorder(BinaryTreeNode<int>*root,vector<int>&ans)
{
    if(root==NULL)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<vector<int>> getTreeTraversal(BinaryTreeNode<int> *root){
    // Write your code here.
    vector<int>inordertraversal;
    vector<int>preordertraversal;
    vector<int>postordertraversal;
    vector<vector<int>>finalAnswer;
    inorder(root,inordertraversal);
    preorder(root,preordertraversal);
    postorder(root,postordertraversal);
    finalAnswer.push_back(inordertraversal);
    finalAnswer.push_back(preordertraversal);
    finalAnswer.push_back(postordertraversal);
    return finalAnswer;
}
