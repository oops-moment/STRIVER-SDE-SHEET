class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(vector<int> adj[],int node, vector<int>&ans,vector<int>&vis)
    {   
        vis[node]=1;
        ans.push_back(node);
        for(auto it : adj[node])
        {
            if(vis[it]==0)
            {
                dfs(adj,it,ans,vis);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        // so the given graph is connected we need to peroform dfs traversal over it
        vector<int>dfs_traversal; // this will sotre the dfs traversal
        vector<int>vis(V,0);
        dfs(adj,0,dfs_traversal,vis);
        return dfs_traversal;
    }
};
