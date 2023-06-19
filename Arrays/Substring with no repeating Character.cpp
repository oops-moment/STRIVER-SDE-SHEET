class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int finalAnswer=0;
        int count=0;
        int leftPointer=0;
        unordered_map<char,int>mp;
        for(int i=0;i<s.length();i++)
        {
            if(mp[s[i]]==0)
            {
                count=i-leftPointer+1;
                finalAnswer=max(finalAnswer,count);
                mp[s[i]]=i+1;
            }
            else
            {
                if(mp[s[i]]-1 >= leftPointer)
                {
                    leftPointer=mp[s[i]];
                    count=i-leftPointer+1;
                    finalAnswer=max(finalAnswer,count);
                    mp[s[i]]=i+1;
                }
                else
                {
                count=i-leftPointer+1;
                finalAnswer=max(finalAnswer,count);
                mp[s[i]]=i+1;
                }
                
            }
        }
        return finalAnswer;
    }
};
