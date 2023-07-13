Make two strings word1 and word2 equal by performing minimum deletions 
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.length()+1,vector<int>(word2.length()+1,0));
        for(int i=1;i<=word1.length();i++)
        {
            for(int j=1;j<=word2.length();j++)
            {
                if(word1[i-1]==word2[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else
                {
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        int n=word1.length();
        int m=word2.length();
        int lcs=dp[n][m];
        return n+m-lcs-lcs;
    }
};
