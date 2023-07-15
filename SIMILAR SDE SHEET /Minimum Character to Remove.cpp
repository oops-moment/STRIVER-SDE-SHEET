class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        // now if none of the character is present then output woild eb the size of the string right
        unordered_map<string,int>mp;
        for(int i=0;i< dictionary.size();i++)
        {
            mp[ dictionary[i]]=1;
        }
        // now let's keep a dp arrya
        int n=s.length();
        vector<int>dp(n+1,0);
        for(int i=1;i<=n;i++)
        {
            dp[i]=1+dp[i-1];
            for(int j=i;j>=1;j--)
            {
                // j-1 is the string ewe are talking about 
                if(mp[s.substr(j-1,i-j+1)])
                {
                    dp[i]=min(dp[i],dp[j-1]);
                }
            }
        }
        return dp[n];
    }
};
