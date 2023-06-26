class Solution {
public:
    bool isValid(int x, int y , int n , int m)
    {
        if(x<0 || y<0 || x>=n || y>=m)
        {
            return 0;
        }
        return 1;
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<int>dx={1,-1,0,0};
        vector<int>dy={0,0,1,-1};
        vector<vector<int>>visited(n,vector<int>(m,-1));
        queue<pair<int,pair<int,int>>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2)
                {
                    q.push({0,{i,j}});
                    visited[i][j]=1;
                }
            }
        }
        int count=0;
        while(!q.empty())
        {
            auto it = q.front();
            q.pop();
            int x= it.second.first;
            int y=it.second.second;
            int time=it.first;
            count=max(count,time);
            for(int i=0;i<4;i++)
            {
                int newx=x+dx[i];
                int newy=y+dy[i];
                if(isValid(newx,newy,n,m))
                {
                    if(grid[newx][newy]==1 &&  visited[newx][newy]==-1)
                    {
                       
                        visited[newx][newy]=1;
                        q.push({time+1,{newx,newy}});
                    }
                }

            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==-1 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
        return count;
    }
};
