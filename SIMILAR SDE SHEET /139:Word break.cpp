class Solution {
public:
    int recurse(string s, int start,int index, unordered_map<string,int>&mp,vector<vector<int>>&dp)
    {
        
        // Now two cases
        if(index==s.length()-1)
        {
            // if that's the last index
        if(mp[s.substr(start,index-start+1)])            {
                return 1;
            }
            return 0;
        }
        if(dp[start][index]!=-1)
        {
                return dp[start][index];
        }   
        int a=0;
        if(mp[s.substr(start,index-start+1)])
        {
            // if this exists in the map may be accept it move 
            a=recurse(s,index+1,index+1,mp,dp);
        }
        int b=recurse(s,start,index+1,mp,dp);
        return dp[start][index]=a|b;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        int length=s.size();
        vector<vector<int>>dp(length+1,vector<int>(length+1,-1));
        for(int i=0;i<wordDict.size();i++)
        {
            mp[wordDict[i]]=1;
        }
        // now we have the map
        return recurse(s,0,0,mp,dp);
    }
};
