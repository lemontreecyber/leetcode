class Solution {
    typedef int dtype;
   
    inline dtype min(dtype a, dtype b) {
        return (a < b) ? a : b;
    }
   
    inline dtype max(dtype a, dtype b) {
        return (b < a) ? a : b;
    }
   
public:
    int getMoneyAmount(int n) {
        // dp[l][r] = answer for guessing in [l + 1, r + 1]
        vector<vector<dtype>> dp(n, vector<dtype>(n, 0));
        for (int delta = 1; delta < n; ++delta) {  // delta = r - l
            for (dtype l = 0; l + delta < n; ++l) {
                dtype r = l + delta;
                dtype m = min(l + 1 + dp[l + 1][r], r + 1 + dp[l][r - 1]);
                for (dtype i = l + 1; i < r; ++i)
                    m = min(m, i + 1 + max(dp[l][i - 1], dp[i + 1][r]));
                dp[l][r] = m;
            }
        }
        return dp[0][n - 1];
    }
};
