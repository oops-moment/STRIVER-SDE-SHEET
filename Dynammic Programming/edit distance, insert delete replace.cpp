class Solution {
public:
    int recurse(string s1,string s2, int index1, int index2,vector<vector<int>>&dp)
    {
        // Base case
        // we  have two cases
         if(index2<0)
        {
            return index1+1;
        }
        if(index1<0)
        {
            return index2+1;
        }
        if(dp[index1][index2]!=-1)
        {
            return dp[index1][index2];
        }
        if(s1[index1]==s2[index2])
        {
            return dp[index1][index2]=recurse(s1,s2,index1-1,index2-1,dp);
        }
        else
        {
            // Now there are three possbile wats
            //1: insert then j decreases i remains the same since you inserted after
            int insert=1+recurse(s1,s2,index1,index2-1,dp);
            // 2: replace in that case both derease with one operating
            int replace=1+recurse(s1,s2,index1-1,index2-1,dp); 
            int deletee=1+recurse(s1,s2,index1-1,index2,dp);
            return dp[index1][index2]=min(insert,min(replace,deletee));
        }

    }
    int minDistance(string word1, string word2) {
        // So the good part about this problem is that we can replace character and thats pretty good;
        int index1=word1.length()-1;
        int index2=word2.length()-1;
        vector<vector<int>>dp(index1+1,vector<int>(index2+1,-1));
       return recurse(word1,word2,index1,index2,dp);
    }
};
