class Solution {
public:
    bool canPartition(vector<int>& nums) {
        size_t const n = nums.size();
        if (n < 2) return false;
        int const total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 2 != 0) return false;
        int const tgt = total >> 1;
        iter_swap(nums.begin(), max_element(nums.begin(), nums.end()));
        sort(nums.begin() + 1, nums.end());  // first is largest, other s->l
        // start dp
        vector<bool> dp(1, true); // dp[i = sums of list 1] = i exists
        if (nums[0] == tgt) return true;
        int upto = 1;  // nums[0] not in list 1, upto = dp.shape
        for (size_t pos = 1; pos < n; ++pos) {
            int const numspos = nums[pos];
            int newupto = min(upto + numspos, tgt);
            vector<bool> newdp(newupto, false);
            for (size_t i = 0; i < upto; ++i) {
                if (!dp[i]) continue;
                if (i + numspos == tgt) return true;  // found!
                newdp[i] = true;
                if (i + numspos > tgt) continue;
                newdp[i + numspos] = true;
            }
            upto = newupto;
            dp = move(newdp);
        }
        return false;
    }
};
