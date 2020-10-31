class Solution {    
public:
    int stoneGameII(vector<int>& piles) {
        int const n = piles.size();
        if (n == 0) return 0;
        vector<int> sums(n + 1);  // sum[i] = sum(piles[i:n])
        int s = 0;
        for (int i = n - 1; i >= 0; --i) {
            s += piles[i];
            sums[i] = s;
        }
        // dp[pos][m - 1] = max first player gain from piles[pos:]
        vector<vector<int>> dp(n);
        for (int i = 0; i < n; ++i)
            dp[i] = vector<int>(i + 1);
        // return max of net gain of first player from piles[pos:]
        function<int(int, int)> dfs = [&](int pos, int m) {
            if (dp[pos][m - 1] != 0) return dp[pos][m - 1];
            if (n - pos <= m * 2) {
                dp[pos][m - 1] = sums[pos];
                return sums[pos];
            }
            int best = INT_MIN;
            int sumspos = sums[pos];
            for (int x = 1; x <= 2 * m; ++x) {
                best = max(best, (sumspos - sums[pos + x]) - dfs(pos + x, max(x, m)));
            }
            dp[pos][m - 1] = best;
            return best;
        };
        return (sums[0] + dfs(0, 1)) / 2;
    }
};
