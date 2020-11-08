class Solution {
public:
    int minimumMoves(vector<int>& arr) {
        size_t const n = arr.size();
        if (n == 0) return 0;
        // dp[i][j] = arr[i, j] can be printed in dp[i][j] + 1 steps
        vector<vector<int>> dp(n, vector<int>(n, -1));
        function<int(size_t, size_t)> dfs = [&](size_t l, size_t r) {
            if (l >= r) return 0;
            if (dp[l][r] >= 0) return dp[l][r];
            int const arrl = arr[l];
            int ans = 1 + dfs(l + 1, r);
            for (size_t i = l + 1; i < r; ++i) {
                if (arr[i] == arrl)
                    ans = min(ans, 1 + dfs(l + 1, i - 1) + dfs(i + 1, r));
            }
            if (arr[r] == arrl)
                ans = min(ans, dfs(l + 1, r - 1));
            return dp[l][r] = ans;
        };
        return dfs(0, n - 1) + 1;
    }
};
