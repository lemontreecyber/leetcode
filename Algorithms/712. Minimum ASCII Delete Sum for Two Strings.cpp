class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        size_t const l1 = s1.length();
        size_t const l2 = s2.length();
        if (l1 == 0 || l2 == 0) {
            string* t;
            if (l1 == 0) t = &s2;
            else t = &s1;
            int sumt = 0;
            for (char c : *t)
                sumt += static_cast<int>(c);
            return sumt;
        }
        vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, INT_MAX));
        dp[0][0] = 0;
        for (size_t i = 0; i < l1; ++i)
            dp[i + 1][0] = dp[i][0] + static_cast<int>(s1[i]);
        for (size_t i = 0; i < l2; ++i)
            dp[0][i + 1] = dp[0][i] + static_cast<int>(s2[i]);
        for (size_t i = 0; i < l1; ++i)
            for (size_t j = 0; j < l2; ++j)
                if (s1[i] == s2[j]) {
                    dp[i + 1][j + 1] = dp[i][j];
                } else {
                    dp[i + 1][j + 1] = min(
                        dp[i][j + 1] + static_cast<int>(s1[i]),
                        dp[i + 1][j] + static_cast<int>(s2[j])
                    );
                }
        return dp[l1][l2];
    }
};
