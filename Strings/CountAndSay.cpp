typedef long long int ll;

const vector<vector<vector<int>>> all = {
    {{0, 0}, {0, 1}, {1, 0}, {1, 1}},           // {0, 0}
    {{0, -1}, {0, 0}, {1, -1}, {1, 0}},         // {0, 1}
    {{-1, 0}, {-1, 1}, {0, 0}, {0, 1}},         // {1, 0}
    {{-1, -1}, {-1, 0}, {0, -1}, {0, 0}}        // {1, 1}
};       

class Solution {
public:
    vector<long long> countBlackBlocks(int m, int n, vector<vector<int>>& coordinates) {
        vector<int> cells (5);
        
        set<pair<int, int>> is_present;
        for (auto c: coordinates) {
            is_present.insert({c[0], c[1]});
        }
        
        for (auto& c: coordinates) {
            for (int i = 0; i < 4; i ++) {
                int black_cells = 0;
                bool is_valid_position = true;
                
                for (auto& diff: all[i]) {
                    int row = c[0] + diff[0];
                    int col = c[1] + diff[1];
                    
                    bool is_valid = (row >= 0 && row < m) && (col >= 0 && col < n);
                    if (!is_valid) {
                        is_valid_position = false;
                        break;
                    }
                    
                    if (is_present.count({row, col})) black_cells ++;
                }
                
                if (!is_valid_position) continue;

                pair<int, int> top_left_cell = {c[0] + all[i][0][0], c[1] + all[i][0][1]};
                cells[black_cells]++;
            }
        }
        
        vector<ll> result(5);
        result[0] = (ll)(n-1) * (m-1);
        for (int i = 1; i <= 4; i ++) {
            result[0] -= cells[i]/i;
            result[i]  = cells[i]/i;
        }
        
        return result;
    }
};
