//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int recurse(int n, int floors, vector<vector<int>>& dp)
    {
        if (n == 1)
        {
            return floors;
        }
        if (floors == 0 || floors == 1)
        {
            return floors;
        }
        if (dp[n][floors] != -1)
        {
            return dp[n][floors];
        }
        int ans = INT_MAX;
        for (int i = 1; i <= floors; i++)
        {
            int op1 = recurse(n - 1, i - 1, dp);
            int op2 = recurse(n, floors - i, dp);
            int temp = 1 + max(op1, op2);
            ans = min(ans, temp);
        }
        return dp[n][floors] = ans;
    }

    int eggDrop(int n, int k)
    {
        vector<vector<int>> dp(n + 1, vector<int>(k + 1, -1));
        return recurse(n, k, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends
