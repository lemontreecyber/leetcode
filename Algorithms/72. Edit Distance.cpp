class Solution {
public:
    int minDistance(string word1, string word2) {
        size_t const m = word1.length();
        size_t const n = word2.length();
        if (m < n) return minDistance(word2, word1);  // assert m >= n
        vector<int> dp(n + 1);
        for (int i = 1; i <= n; ++i) dp[i] = i;
        for (size_t i = 0; i < m; ++i) {
            vector<int> newdp(n + 1);
            newdp[0] = i + 1;
            for (size_t j = 0; j < n; ++j) {
                if (word1[i] == word2[j])
                    newdp[j + 1] = dp[j];
                else
                    newdp[j + 1] = 1 + min(dp[j], min(dp[j + 1], newdp[j]));
            }
            dp = move(newdp);
        }
        return dp[n];
    }
};

