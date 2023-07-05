
        // so we gonna find out the minimum spanning tree 
        vector<int>visited(V,0); // initaially makring all as unvisited
        // we gonna store the edege weight and then sum gonna store the final sum derank
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        int sum=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            auto it = pq.top();
            int node = it.second;
            int dist=it.first;
            pq.pop();
            // so we now have node and distance
            if(visited[node]==1)
            {
                continue;
            }
            if(visited[node]==0)
            {
                sum+=dist;
                visited[node]=1;
                for(auto nodes : adj[node])
                {    
                    int adjn=nodes[0];
                    int edjw=nodes[1];
                    if(visited[adjn]==0)
                    {   
                        pq.push({edjw,adjn});
                    }
                }
            }
        }
        return sum;
