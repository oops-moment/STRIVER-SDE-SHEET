class Solution {
public:
    int romanToInt(string s) {
        // so instead of computing the value everytim we will store it in some map
        unordered_map<char,int>mp={{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
        int answer=0;
        for(int i=0;i<s.length()-1;i++)
        {
            if(mp[s[i]]<mp[s[i+1]])
            {
                answer-=mp[s[i]];
            }
            else
            {
                answer+=mp[s[i]];
            }
        }
        answer+=mp[s[s.length()-1]];
        return answer;

    

    }
};
