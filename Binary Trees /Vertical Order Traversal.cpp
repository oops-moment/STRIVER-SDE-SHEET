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
    static bool cmp(pair<int,int>a,pair<int,int>b)
    {
        if(a.second==b.second)
        {
            return a.first<b.first;
        }
        else
        {
            return a.second<b.second;
        }
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
    vector<vector<int>> finalAnswer;
    map<int, vector<pair<int, int>>> mp;
    queue<pair<TreeNode*, pair<int, int>>> q;
    if (root == NULL) {
        return finalAnswer;
    }
    q.push({ root, {0, 0} });
    while (!q.empty()) {
        auto it = q.front();
        TreeNode* temp = it.first;
        int vindex = it.second.first;
        int hindex = it.second.second;
        q.pop();
        mp[vindex].push_back({ temp->val, hindex });
        if (temp->right) {
            q.push({ temp->right, {vindex + 1, hindex + 1} });  // Corrected typo here
        }
        if (temp->left) {
            q.push({ temp->left, {vindex - 1, hindex + 1} });  // Corrected typo here
        }
    }
    for (auto it : mp) {
        sort(it.second.begin(), it.second.end(), cmp);
        vector<int> temp;
        for (auto node : it.second) {
            temp.push_back(node.first);  // Fixed using "node.first" instead of "it.first"
        }
        finalAnswer.push_back(temp);
    }
    return finalAnswer;
}

};
