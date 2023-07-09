/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    void dfs(Node* node,unordered_map<Node*,int>&visited, unordered_map<Node*,Node*>&mp)
    {
        visited[node]=1;
        mp[node]=new Node(node->val);
        for(auto it : node->neighbors)
        {
            // these it are the nodes*
            if(visited[it]==0)
            {
                dfs(it,visited,mp);
            }
        }

    }
    Node* cloneGraph(Node* node) {
        if(node==NULL)
        {
            return NULL;
        }
        unordered_map<Node*,Node*>mp;
        // sp here we can map old nodes to the new nodes okay
        unordered_map<Node*,int>visited;
        // ispe krenge dfs traversal
        dfs(node,visited,mp);
        // now value part is done now we need to do the neighbours vala part
        for(auto it : mp)
        {
            Node* orig = it.first;
            Node* neww = it.second;
            for(auto it : orig->neighbors)
            {
                neww->neighbors.push_back(mp[it]);
            }

        }

        return mp[node];
        
    }
};
