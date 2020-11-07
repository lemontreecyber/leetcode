class Solution {
public:
    int strangePrinter(string s) {
        size_t const n = s.size();
        if (n <= 1) return n;
        // dp[i][j] = ans for s[i, j]
        vector<vector<int>> dp(n, vector<int>(n));
        function<int(size_t, size_t)> dfs = [&](size_t l, size_t r) {
            if (l > r) return 0;
            if (l == r) return 1;
            if (dp[l][r] > 0) return dp[l][r];
            char const sl = s[l];
            int ans = dfs(l + 1, r) + 1;
            for (size_t i = r; i > l; --i) {
                if (s[i] == sl)
                    ans = min(ans, dfs(l + 1, i - 1) + dfs(i, r));
            }
            return dp[l][r] = ans;
        };
        return dfs(0, n - 1);
    }
};
