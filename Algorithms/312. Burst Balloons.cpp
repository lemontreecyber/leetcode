class Solution {
public:
    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        size_t const n = nums.size();
        // dp[i][j] = max value from bursting nums(i, j)
        vector<vector<int>> dp(n, vector<int>(n));
        for (size_t dist = 1; dist < n; ++dist) {
            for (size_t l = 0, r = dist; r < n; ++l, ++r) {
                int coin = 0;
                int const numslr = nums[l] * nums[r];
                for (size_t m = l + 1; m < r; ++m)
                    coin = max(coin, dp[l][m] + dp[m][r] + nums[m] * numslr);
                dp[l][r] = coin;
            }
        }
        return dp[0][n - 1];
    }
};
