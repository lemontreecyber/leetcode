class Solution {
public:
    int maxProduct(vector<int>& nums) {
        size_t const n = nums.size();
        if (n == 0) return 1;
        int big = nums[0], small = nums[0], ans = nums[0];
        for (int i = 1; i < n; ++i) {
            int const up = big * nums[i];
            int const down = small * nums[i];
            big = max(max(up, down), nums[i]);
            small = min(min(up, down), nums[i]);
            ans = max(big, ans);
        }
        return ans;
    }
};
