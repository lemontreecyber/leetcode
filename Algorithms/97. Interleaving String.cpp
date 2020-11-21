class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        size_t const l1 = s1.length();
        size_t const l2 = s2.length();
        size_t const l3 = s3.length();
        if (l1 + l2 != l3) return false;
        // s1[0, i) interleave s2[0, j) => s3[0, i+j)
        vector<vector<bool>> dp(l1 + 1, vector<bool>(l2 + 1));
        dp[0][0] = true;
        for (size_t i = 0; i <= l1; ++i) {
            for (size_t j = 0; j <= l2; ++j) {
                if (i > 0)
                    dp[i][j] = dp[i - 1][j] && s1[i - 1] == s3[i + j - 1];
                if (j > 0)
                    dp[i][j] = dp[i][j] || (dp[i][j - 1] && s2[j - 1] == s3[i + j - 1]);
            }
        }
        return dp[l1][l2];
    }
};
