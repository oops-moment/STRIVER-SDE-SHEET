
class Solution
{    
    // recursion is exceeding time so lets take memoisaton
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int recurse(int index,int weight,int wt[],int val[],vector<vector<int>>&dp)
    {
        if(index==0)
        {   
         if(weight>=wt[0])
         {
             return val[0];
         }
         else
         {
             return 0;
         }
        }
        if(dp[index][weight]!=-1)
        {
            return dp[index][weight];
        }
        // so we will chek if the weight index is less than weight we gonna condier it
        int take=INT_MIN;
        if(wt[index]<=weight)
        {
           take= val[index]+recurse(index-1,weight-wt[index],wt,val,dp);
        }
       int nottake= recurse(index-1,weight,wt,val,dp);
       return (dp[index][weight]=max(take,nottake));
        
    }
    int knapSack(int W, int wt[], int val[], int n) 
    { 
       // Your code here
       vector<vector<int>>dp(n,vector<int>(W+1,-1));
       return recurse(n-1,W,wt,val,dp);

    }
};
