class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        size_t const len = cuts.size() + 2;
        cuts.push_back(0);
        sort(cuts.begin(), cuts.end());
        cuts.push_back(n);
        // dp[i][j] = cost of cut from cuts[i] to cuts[j]
        vector<vector<int>> dp(len, vector<int>(len));
        function<int(size_t, size_t)> dfs = [&](size_t l, size_t r) {
            if (r - l <= 1) return 0;
            if (dp[l][r] > 0) return dp[l][r];
            int m = INT_MAX;
            for (size_t i = l + 1; i < r; ++i) {
                m = min(m, dfs(l, i) + dfs(i, r));
            }
            return dp[l][r] = m + cuts[r] - cuts[l];
        };
        return dfs(0, len - 1);
    }
};
