class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, -1);
        dp[0] = 1;
        function<int(int)> dfs = [&](int t) {
            if (t < 0) return 0;
            if (dp[t] >= 0) return dp[t];
            int cnt = 0;
            for (int c : nums)
                cnt += dfs(t - c);
            return dp[t] = cnt;
        };
        return dfs(target);
    }
};
