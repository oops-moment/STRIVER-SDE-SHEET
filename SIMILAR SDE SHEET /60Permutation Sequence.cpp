class Solution {
public:
    string getPermutation(int n, int k) {
        // so okay
        vector<int>temp;
        for(int i=1;i<=n;i++)
        {
            temp.push_back(i);
        }
        do
        {
            k--;
        }while(k && next_permutation(temp.begin(),temp.end()));
        string ans="";
        for(int i=0;i<temp.size();i++)
        {
            ans+=to_string(temp[i]);
        }
        return ans;
    }
};
