class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        size_t const n = nums.size();
        if (n <= 2) return true;
        vector<int> dp(nums);
        for (size_t step = n - 1; step > 0; --step) {
            vector<int> ndp(step);
            for (size_t i = 0, j = n - step; j < n; ++i, ++j)
                ndp[i] = max(nums[i] - dp[i + 1], nums[j] - dp[i]);
            dp = move(ndp);
        }
        return dp[0] >= 0;
    }
};
