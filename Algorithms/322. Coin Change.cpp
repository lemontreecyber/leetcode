class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        if (n == 0) return amount == 0 ? 0 : -1;
        vector<int> dp(amount + 1, amount + 1);  // dp[i] = ans[i]
        // amount + 1 is max int
        dp[0] = 0;
        for (int i = 1; i <= amount; ++i) {
            for (int c : coins) {
                if (i - c >= 0 && dp[i - c] < amount)
                    dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
        return dp[amount] > amount ? -1 : dp[amount];
    }
