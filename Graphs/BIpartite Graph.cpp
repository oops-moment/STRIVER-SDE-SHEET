class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
       // so lets do that
       int totalNodes=graph.size();
       vector<int>color(totalNodes,-1);
       for(int i=0;i<totalNodes;i++)
       {
           if(color[i]==-1)
           {   
               queue<pair<int,int>>q;
               color[i]=0;
               q.push({i,0});
               while(!q.empty())
               {
                   int node=q.front().first;
                   int c=q.front().second;
                   q.pop();
                   for(auto it : graph[node])
                   {
                       if(color[it]==c)
                       {
                           return 0;
                       }
                       else
                       {
                           if(color[it]==-1)
                           {
                               color[it]=1-c;
                               q.push({it,1-c});
                           }
                       }
                   }
               }

           }
       }  
       return 1;
    }
};
