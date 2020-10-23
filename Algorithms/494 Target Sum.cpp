class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        size_t n = nums.size();
        if (n == 0 && S != 0) return 0;
        // boarder array
        vector<int> sums(n + 1);
        for (int i = n - 1; i > 0; --i)
            sums[i] = abs(nums[i]) + sums[i + 1];
        // dp
        vector<unordered_map<int, int>> dp(n);
        ++dp[0][nums[0]];
        ++dp[0][-nums[0]];
        for (int i = 1; i < n; ++i) {
            auto& um = dp[i];
            for (auto& p : dp[i - 1]) {
                if (p.first + sums[i] < S || p.first - sums[i] > S)
                    continue;
                um[p.first + nums[i]] += p.second;
                um[p.first - nums[i]] += p.second;
            }
        }
        return dp[n - 1][S];
    }
};
