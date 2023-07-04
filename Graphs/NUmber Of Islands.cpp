#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool isvalid(int newx, int newy, int n, int m)
    {
        if (newx < 0 || newy < 0 || newx >= n || newy >= m)
        {
            return false;
        }
        return true;
    }
    
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(), vector<int>(grid[0].size(), 0));
        int count = 0;
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (visited[i][j] == 0 && grid[i][j] == '1')
                {   
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = 1;
                    
                    while (!q.empty())
                    {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();
                        
                        for (int k = 0; k < 4; k++)
                        {
                            int newx = x + dx[k];
                            int newy = y + dy[k];
                            
                            if (isvalid(newx, newy, grid.size(), grid[0].size()) && visited[newx][newy] == 0 && grid[newx][newy] == '1')
                            {
                                q.push({newx, newy});
                                visited[newx][newy] = 1;
                            }
                        }
                    }
                }
            }
        }
        
        return count;
    }
};
