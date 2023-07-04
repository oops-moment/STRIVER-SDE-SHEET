vector<int> bfsOfGraph(int n, vector<int> adj[]) {
              vector<int>visited(n+1 , false);
              queue<int>q;
              visited[0] = true ;
              q.push(0);
              vector<int>ans ;
              while(!q.empty()){
                  int p = q.front();
                  ans.push_back(p);
                  q.pop();
                  for(auto it : adj[p]){
                      if(!visited[it]){
                          visited[it] = true ;
                          q.push(it);
                      }
                  }
              }
              return ans ;
    }
