class Solution {
public:
    int change(int amount, vector<int>& coins) {
        if (amount <= 0) return (amount == 0) ? 1 : 0;
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int c : coins) {
            for (int i = 1; i <= amount; ++i) {
                if (i - c >= 0)
                    dp[i] += dp[i - c];
            }
        }
        return dp[amount];
    }
};

