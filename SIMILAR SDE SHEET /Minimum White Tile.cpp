#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
public:
    int recurse(const string& floor, int carpets, int length, int index, vector<int>& suffix,vector<vector<int>>&dp) {
        if (index >= floor.size()) {
            return 0;
        }
        if (carpets <= 0) {
            return suffix[index];
        }
        if(dp[index][carpets]!=-1)
        {
            return dp[index][carpets];
        }
        if (floor[index] == '1') {
                int use = recurse(floor, carpets - 1, length,index + length, suffix,dp);
                int notuse = 1 + recurse(floor, carpets, length, index + 1, suffix,dp);
                return dp[index][carpets]=min(use, notuse);
            }
        
        return dp[index][carpets]=recurse(floor, carpets, length, index + 1, suffix,dp);
    }

    int minimumWhiteTiles(string floor, int numCarpets, int carpetLen) {
        int n = floor.size();
        vector<int> suffix(n, 0);
        suffix[n - 1] = (floor[n - 1] == '1') ? 1 : 0;
        for (int i = n - 2; i >= 0; i--) {
            if (floor[i] == '1') {
                suffix[i] = 1 + suffix[i + 1];
            }
            else {
                suffix[i] = suffix[i + 1];
            }
        }
        vector<vector<int>>dp(n,vector<int>(numCarpets+1,-1));

        return recurse(floor, numCarpets, carpetLen, 0, suffix,dp);
    }
};
