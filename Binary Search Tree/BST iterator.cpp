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
class BSTIterator {
public:
// we dont want o(n) firs tof all we would have stored inorder traversal and got the answer;
    
    stack<TreeNode*>stck;
    void pushall(TreeNode*root)
    {
        while(root!=NULL)
        {
            stck.push(root);
            root=root->left;
        }
    }
    BSTIterator(TreeNode* root) {
        pushall(root);
    }
    
    int next() {
        if(stck.empty())
        {
            return -1;
        }
        else
        {
            TreeNode*temp=stck.top();
            int ans=temp->val;
            stck.pop();
            if(temp->right)
            {
                pushall(temp->right);
            }
            return ans;
            
        }
        
    }
    
    bool hasNext() {
        if(stck.empty())
        {
            return 0;
        }
        return 1;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
