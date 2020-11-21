class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t l1 = word1.length();
        size_t l2 = word2.length();
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1));
        for (int i = 1; i <= l1; ++i) dp[i][0] = i;
        for (int i = 1; i <= l2; ++i) dp[0][i] = i;
        for (size_t i = 0; i < l1; ++i)
            for (size_t j = 0; j < l2; ++j)
                if (word1[i] == word2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = 1 + min(dp[i][j + 1], dp[i + 1][j]);
                }
        return dp[l1][l2];
    }
};
