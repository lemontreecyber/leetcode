class Solution {
public:
    int minInsertions(string s) {
        size_t const n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, -1));  // ans for [i, j]
        function<int(size_t, size_t)> dfs = [&](size_t i, size_t j) {
            if (i >= j) return 0;
            if (dp[i][j] >= 0) return dp[i][j];
            if (s[i] == s[j]) {
                return dp[i][j] = dfs(i + 1, j - 1);
            } else {
                return dp[i][j] = 1 + min(dfs(i, j - 1), dfs(i + 1, j));
            }
        };
        return dfs(0, n - 1);
    }
};
