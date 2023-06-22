#include <bits/stdc++.h> 
 bool valid (vector<vector<int>> &graph, int node, int colour,vector<int>&color, int n)
    {
        for(int i=0;i<n;i++)
        {
            if(i!=node && graph[i][node]==1 && color[i]==colour )
            {
                return false;
            }
        }
        return true;
    }
    bool recurse(vector<int>&color,vector<vector<int>> &graph, int m, int n, int node)
    
     {
        if(node==n)
        {
            return  true;
        }
        for(int i=1;i<=m;i++)
        {
            if(valid(graph,node,i,color,n))
            {   
                color[node]=i;
                if(recurse(color,graph,m,n,node+1)== true)
                {
                    return true;
                }
                else
                {
                    color[node]=0;
                }
            }
        }
        return  false;
    }

string graphColoring(vector<vector<int>> &mat, int m) {
    // Write your code here
    int n = mat.size();
    vector<int>color(n,0); // initially all are uncolored
    int node=0;
    int ans= recurse(color,mat,m,n,node);
    if(ans)
    {
        return "YES";
    }
    return "NO";
}
