class Solution {
public:
    TreeNode* build(vector<int>& preorder, int preorderstart, int preorderend, vector<int>& inorder, int inorderstart, int inorderend, unordered_map<int, int>& mp) {
        if (preorderstart > preorderend) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(preorder[preorderstart]);
        int inroot = mp[root->val];
        int leftSubtreeSize = inroot - inorderstart;
        
        root->left = build(preorder, preorderstart + 1, preorderstart + leftSubtreeSize, inorder, inorderstart, inroot - 1, mp);
        root->right = build(preorder, preorderstart + leftSubtreeSize + 1, preorderend, inorder, inroot + 1, inorderend, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        int preorderstart = 0;
        int preorderend = preorder.size() - 1;
        int inorderstart = 0;
        int inorderend = inorder.size() - 1;
        
        return build(preorder, preorderstart, preorderend, inorder, inorderstart, inorderend, mp);
    }
};
