class Solution {
public:
    vector<int>dx={-1,-1,-1,0,0,1,1,1};
    vector<int>dy={-1,0,1,-1,1,-1,0,1};
    bool isValid(int x, int y, int n , int m)
    {
        if(x<0 || y<0 || x>=n ||y>=m)
        {
            return 0;
        }
        return 1;
    }
    int calculateLyf(vector<vector<int>>copy, int x , int y)
    {
        // this function returns the number of live neighbours to the cell i,j
        int count=0;
        int n=copy.size();
        int m=copy[0].size();
        for(int i=0;i<8;i++)
        {
            int newx=x+dx[i];
            int newy=y+dy[i];
            if(isValid(newx,newy,n,m))
            {
                if(copy[newx][newy]%2==1)
                {
                    count++;
                }
            }   
        }
        return count;
    }
    void gameOfLife(vector<vector<int>>& board) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                // here we pass
                int lives=calculateLyf( board,i,j);
                if(board[i][j]==0)
                {
                    // if it is dead
                     if(lives==3)
                     {
                         board[i][j]+=2;
                     }
                }
                else
                {
                    
                    if(lives==2 || lives==3)
                    {
                        board[i][j]+=2; // becomes 3
                    }
                }
            }
        }
        // now divide by 2 yo hoo
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                board[i][j]/=2;
            }
        }
        
    }
};










// we can do like if the cell is dead abhi but became alive we add 2 to it 2 just modulp
