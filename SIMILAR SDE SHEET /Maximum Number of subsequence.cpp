class Solution {
public:
    long long solve(string original,string pattern)
    {
        long long sum=0;
        long long int count=0;
        long long int flag=0;
        for(int i=0;i<original.length();i++)
        {   
            
            if((original[i]==pattern[0]) && (original[i]==pattern[1] ))
            {
               if(flag==1)
               {
                   sum+=count;
                   count++;
               }
               else
               {
                   count++;
                   flag=1;
                                  }
            }
            else if(original[i]==pattern[0])
            {
                count++;
                flag=1;
            }
            else if(original[i]==pattern[1])
            {
                sum+=count;
            }         
        }
        return sum;
    }
    long long maximumSubsequenceCount(string text, string pattern) {
        // either you will insert pattern 0 at the first 
        // or you will insert patern[1] at the last either of the two optino gonna yiedld the answer
        long long int cnt1=solve(text+pattern[1],pattern);
        long long int cnt2=solve(pattern[0]+text,pattern);
         return max(cnt1,cnt2);

    }
};
