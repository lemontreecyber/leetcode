class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int const n = costs.size();
        if (n == 0) return 0;
        vector<int> dp(3);
        constexpr int O[3][2] {{1, 2}, {0, 2}, {0, 1}};
        for (int house = 0; house < n; ++house) {
            vector<int> newdp(3);
            for (int i = 0; i < 3; ++i)
                newdp[i] = costs[house][i] + min(dp[O[i][0]], dp[O[i][1]]);
            dp = move(newdp);
        }
        return *min_element(dp.begin(), dp.end());
    }
};
