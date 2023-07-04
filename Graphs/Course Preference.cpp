class Solution {
public:
    bool iscycle(int node, vector<int>&visited,vector<int>&path,vector<int>adj[])
   {
       visited[node]=1;
       path[node]=1;
       for(auto it: adj[node])
       {
           if(visited[it]==0)
           {
               if(iscycle(it,visited,path,adj))
               {
                   return true;
               }
            }
            else
            {
                if(path[it]==1)
                {
                    return true;
                }
            }
             
       }
       path[node]=0;
       return false;
      
   }
    bool canFinish(int numCourses, vector<vector<int>>& pre) {
        // if there is cycle in the directed graph then the answer isNO 
        vector<int>adj[numCourses];
        for(int i=0;i<pre.size();i++)
        {
            adj[pre[i][1]].push_back(pre[i][0]);
        }
        // this is the adjacency listy
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        for(int i=0;i<numCourses;i++)
        {
            if(visited[i]==0)
            {
                if(iscycle(i,visited,path,adj))
                {
                    return false;
                }
            }
        }
        return true;
        
    }
};
