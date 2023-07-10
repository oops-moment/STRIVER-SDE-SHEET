class Solution {
public:
    bool isItPossible(string word1, string word2) {
       vector<int>freq1(26,0);
       vector<int>freq2(26,0);
       for(int i=0;i<word1.length();i++)
       {
           freq1[word1[i]-'a']++;
       }
       for(int i=0;i<word2.length();i++)
       {
           freq2[word2[i]-'a']++;
       }
       for(int i=0;i<26;i++)
       {
           for(int j=0;j<26;j++)
           {
               if(freq1[i]&&freq2[j])
               {
// we will swap thwm
freq1[i]--;
freq2[j]--;
freq1[j]++;
freq2[i]++;
int count1=0;
int count2=0;
for(int i=0;i<26;i++)
{
    if(freq1[i])
    {
        count1++;
    }
    if(freq2[i])
    {
        count2++;
    }
}
if(count1==count2)
{
    return true;
}
// idhar nahi toh 
freq1[i]++;
freq2[j]++;
freq1[j]--;
freq2[i]--;
               }
           }
       }
      return false;
    }
};
