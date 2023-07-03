class Solution {
public:
    TreeNode* build(vector<int>& postorder, int postorderstart, int postorderend, vector<int>& inorder, int inorderstart, int inorderend, unordered_map<int, int>& mp) {
        if (inorderstart > inorderend) {
            return nullptr;
        }
        
        TreeNode* root = new TreeNode(postorder[postorderstart]);
        int inroot = mp[root->val];
        int leftSubtreeSize = inroot - inorderstart;
        
        root->left = build(postorder, postorderend+leftSubtreeSize-1, postorderend, inorder, inorderstart, inroot - 1, mp);
        root->right = build(postorder, postorderstart - 1, postorderend +leftSubtreeSize , inorder, inroot + 1, inorderend, mp);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> mp;
        for (int i = 0; i < inorder.size(); i++) {
            mp[inorder[i]] = i;
        }
        
        int postorderstart = postorder.size() - 1;
        int postorderend = 0;
        int inorderstart = 0;
        int inorderend = inorder.size() - 1;
        
        return build(postorder, postorderstart, postorderend, inorder, inorderstart, inorderend, mp);
    }
};
