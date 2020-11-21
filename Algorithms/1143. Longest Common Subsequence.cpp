class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        size_t const l1 = text1.length();
        size_t const l2 = text2.length();
        if (l1 == 0 || l2 == 0) return 0;
        // ans for text1[0, i), text2[0, j)
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        for (size_t i = 1; i <= l1; ++i) {
            for (size_t j = 1; j <= l2; ++j) {
                if (text1[i - 1] == text2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[l1][l2];
    }
};
