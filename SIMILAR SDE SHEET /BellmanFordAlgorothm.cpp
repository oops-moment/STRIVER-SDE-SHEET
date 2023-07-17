// User function Template for C++

class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        // djikstra algorithm if used in the grpah containg negative cycle would lead to continuous decrease
        // leading to an inifnte cycke hence we know tha in the worst case it take v iteration for everyone to update if still some one is upadtin
        // there is negativ cyele mam
        vector<int>distance(V,1e8);
        distance[S]=0;
        
        for(int i=0;i<V-1;i++) // V-1 iterations
        {
            for(auto it : edges)
            {
                int from=it[0];
                int to=it[1];
                int dist=it[2];
                if(distance[to]>(distance[from]+dist))
                {
                    distance[to]=distance[from]+dist;
                }
            }
        }
        int flag=0;
        for(auto it : edges)
            {   
                
                int from=it[0];
                int to=it[1];
                int dist=it[2];
                if(distance[to]>distance[from]+dist)
                {
                    distance[to]=distance[from]+dist;
                    flag=1;
                    break;
                }
            }
            if(flag)
            {   
                vector<int>vec={-1};
                return vec;
            }
            else
            {
                return distance;
            }
        
    }
};
