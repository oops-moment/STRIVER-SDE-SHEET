class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int MaxProfit=0;
        int MinimumPrice=prices[0];
        for(int i=0;i<prices.size();i++)
        {
            MinimumPrice=min(MinimumPrice,prices[i]);
            MaxProfit=max(MaxProfit,prices[i]-MinimumPrice);
        }
        return MaxProfit;
    }
};
