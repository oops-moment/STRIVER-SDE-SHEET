// here not only we had to tell if it is possible but also if possible give order for which we used stacl
class Solution {
public:
    bool cycle(vector<int>adj[],int node,vector<int>&visited,vector<int>&path,stack<int>&stck)
    {
        visited[node]=1;
        path[node]=1;
        for(auto it : adj[node])
        {
            if(visited[it]==0)
            {
                if(cycle(adj,it,visited,path,stck))
                {
                    return true;
                }
            }
            else
            {
                if(path[it]==1)
                {
                    // visitn twice since cicular
                    return true;
                }
            }
        }
        path[node]=0;
        stck.push(node);
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
          vector<int>adj[numCourses];
        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // so this is the adjaceny list we have
        vector<int>visited(numCourses,0);
        vector<int>path(numCourses,0);
        vector<int>finalAns;
        stack<int>stck;
        for(int i=0;i<numCourses;i++)
        {  
            if(visited[i]==0)
            {
                if(cycle(adj,i,visited,path,stck))
                {
                    return finalAns;
                }
            }
            
           
        }
        while(!stck.empty())
        {
            finalAns.push_back(stck.top());
            stck.pop();
        }
        return  finalAns;

    }
};
