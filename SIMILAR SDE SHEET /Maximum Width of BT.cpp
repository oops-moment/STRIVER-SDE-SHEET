#include <queue>
#include <limits>

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        
        int maxWidth = 0;
        std::queue<std::pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int levelSize = q.size();
            unsigned long long levelStart = q.front().second;
            unsigned long long levelEnd = q.front().second;
            
            for (int i = 0; i < levelSize; i++) {
                TreeNode* node = q.front().first;
                unsigned long long index = q.front().second;
                q.pop();
                
                if (node->left) {
                    q.push({node->left, 2 * index});
                }
                
                if (node->right) {
                    q.push({node->right, 2 * index + 1});
                }
                
                levelEnd = index;
            }
            
            int currentWidth = levelEnd - levelStart + 1;
            maxWidth = std::max(maxWidth, currentWidth);
        }
        
        return maxWidth;
    }
};
