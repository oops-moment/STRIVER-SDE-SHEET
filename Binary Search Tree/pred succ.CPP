#include <bits/stdc++.h>  using namespace std;

void inOrder(vector<int>& result , BinaryTreeNode<int>* root ){    //base case    if(root == NULL) return;

   //Left    inOrder(result , root->left);    //Node    result.push_back(root->data);    //Right    inOrder(result , root->right); }

pair<int,int> predecessorSuccessor(BinaryTreeNode<int>* root, int key) {    vector<int>result;    inOrder(result , root );

   pair<int,int>ans;

   for(int i=0; i<result.size();i++){        if(result[i] == key){        //Pre        ans.first =  (i==0) ? -1 :  result[i-1];        //Post        ans.second = (i==result.size()-1) ?  -1 : result[i+1];        }    }    return ans; }  
