class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        size_t const n = stoneValue.size();
        stoneValue.push_back(0);
        stoneValue.push_back(0);
        stoneValue.push_back(0);
        vector<int> dp(n + 3);
        for (size_t i = n - 1; i < n; --i) {
            dp[i] = max(max(
                stoneValue[i] - dp[i + 1],
                stoneValue[i] + stoneValue[i + 1] - dp[i + 2]),
                stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[i + 3]
            );
        }
        return dp[0] == 0 ? "Tie" : (dp[0] > 0 ? "Alice" : "Bob");
    }
};
