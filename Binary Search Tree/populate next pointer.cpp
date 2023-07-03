/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // lets store the nodes levele wise and then acheive this 
        if(root==NULL)
        {
            return root;
        }
        queue<Node*>q;
        vector<vector<Node*>>final;
        while(!q.empty())
        {
            int size=q.size();
            vector<Node*>tempo;
            for(int i=0;i<size;i++)
            {
                Node* temp : q.front();
                q.pop();
                tempo.push_back(temp);
                if(temp->left)
                {
                    q.push_back(temp->left);
                }
                if(temp->right)
                {
                    q.push_back(temp->right);
                }


            }
            final.push_back(temp);
        }
        
    }
};



BRO O(N) SC
#include <bits/stdc++.h>

void connectNodes(BinaryTreeNode<int> *root) {
  if (!root)
    return;

  queue<BinaryTreeNode<int> *> q;
  q.push(root);

  while (!q.empty()) {
    int n = q.size();
    while (n--) {
      auto p = q.front();
      q.pop();

      p->next = n ? q.front() : NULL;
      if (p->left)
        q.push(p->left);
      if (p->right)
        q.push(p->right);
    }
  }
}
