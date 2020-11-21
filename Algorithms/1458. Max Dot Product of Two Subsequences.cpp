class Solution {
    constexpr static int MINPAD = -1e7;
   
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        size_t const m = nums1.size();
        size_t const n = nums2.size();
        if (m < n) return maxDotProduct(nums2, nums1);  // assert m >= n
        vector<int> dp(n + 1, MINPAD);
        for (size_t i = 0; i < m; ++i) {
            vector<int> newdp(n + 1, MINPAD);
            for (size_t j = 0; j < n; ++j) {
                newdp[j + 1] = max(
                    max(0, dp[j]) + nums1[i] * nums2[j],
                    max(dp[j + 1], newdp[j])
                );
            }
            dp = move(newdp);
        }
        return dp[n];
    }
};

