#include <bits/stdc++.h> 
void recurse(string s ,vector<string>&finalAnswer,int index)
{
    //Base cAse
    if(index==s.length()-1)
    {
        finalAnswer.push_back(s);
        return;
    }
    for(int i=index;i<s.length();i++)
    {
        swap(s[index],s[i]);
        recurse(s,finalAnswer,index+1);
        swap(s[index],s[i]);
    }
}
vector<string> findPermutations(string &s) {
    // Write your code here.
    int index=0;
    vector<string>finalAnswer;
    recurse(s,finalAnswer, index);
    return finalAnswer;
}
