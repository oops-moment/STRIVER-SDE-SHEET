class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        unordered_map<char,int>mp;
        unordered_map<char,int>present;
        for(int i=0;i<chars.size();i++)
        {
            mp[chars[i]]=vals[i];
            present[chars[i]]=1;

        }
        vector<int>temp;
        for(int i=0;i<s.size();i++)
        {
            // now for this particular character 
            if(present[s[i]]==1)
            {
                temp.push_back(mp[s[i]]);
            }
            else
            {
                temp.push_back(s[i]-'a'+1);
            }
        }
        // now that we have temp where in we have integers in it 
        int ans=0;
        int currentsum=0;
        for(int i=0;i<temp.size();i++)
        {
            currentsum+=temp[i];
            ans=max(ans,currentsum);
            if(currentsum<0)
            {
                currentsum=0;
            }
        }
        return ans;
    }
};
