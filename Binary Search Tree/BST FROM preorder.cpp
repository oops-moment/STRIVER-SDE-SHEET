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
    void insert(TreeNode* root, int element)
    {
        if(element<root->val)
        {
            if(root->left==NULL)
            {
                root->left=new TreeNode(element);
                return ;
            }
            else
            {
                insert(root->left,element);
            }
        }
        else
        {
            if(root->right==NULL)
            {
                root->right=new TreeNode(element);
                return;
            }
            else
            {
                insert(root->right,element);

            }
        }
        return;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size()==0)
        {
            return NULL;
        }
        TreeNode* root=new TreeNode( preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
            insert(root,preorder[i]);
        }
        return root;
    }
};
