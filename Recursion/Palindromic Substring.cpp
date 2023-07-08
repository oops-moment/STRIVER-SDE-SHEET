class Solution {
public:
    bool ispal(string S, int start, int end)
    {
        while(start<=end)
        {
            if(S[start]!=S[end])
            {
                return false;
            }
            start++;
            end--;
        }
        return 1;
    }
    void recurse(int index,vector<string>&temp,vector<vector<string>>&finalAnswer,string S)
    {
        if(index==S.length())
        {
            finalAnswer.push_back(temp);
            return;
        }
        for(int i=index;i<S.length();i++)
        {
            
            if(ispal(S,index,i))
            {
                temp.push_back(S.substr(index,i-index+1));
                recurse(i+1,temp,finalAnswer,S);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        int index=0;
        vector<string>temp;
        vector<vector<string>>finalAnswer;
        
        recurse(0,temp,finalAnswer,s);
        return finalAnswer;
    }
};
