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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>finalAnswer;
        if(root==NULL)
        {
            return finalAnswer;
        }
        queue<TreeNode*>q;
        q.push(root);
        int count=0;
        while(!q.empty())
        {
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;i++)
            {
                TreeNode* tempo=q.front();
                q.pop();
                temp.push_back(tempo->val);
                if(tempo->left)
                {
                    q.push(tempo->left);
                }
                if(tempo->right)
                {
                    q.push(tempo->right);
                }
            }
            reverse(temp.begin(),temp.end());
            count++;
            if(count%2==0)
             finalAnswer.push_back(temp);
            else
            {  
                reverse(temp.begin(),temp.end());
              finalAnswer.push_back(temp);

            }

        }
        return finalAnswer;
    }
};
