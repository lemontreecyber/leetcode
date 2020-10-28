class Solution {
    size_t n;
    size_t tgt;  // length of one edge
    vector<int> nums;
   
    bool dfs(int done, int sum, int state) {
        // done = how many edges have been found
        // sum = the total length found of the on-working edge
        // state&(1<<i) is 1 means the i-th stick has been used
        if (done == 4) return true;
        if (sum == tgt) return dfs(done + 1, 0, state);
        for (size_t i = 0; i < n; ++i) {
            if ((state & (1 << i)) > 0) continue;
            int numsi = nums[i];
            if (sum + numsi > tgt) continue;
            if (dfs(done, sum + numsi, state | (1 << i)))
                return true;
            if (sum == 0) return false;  // symmetry
        }
        return false;
    }
   
public:
    bool makesquare(vector<int>& nums) {
        n = nums.size();
        if (n < 4) return false;
        int const total = accumulate(nums.begin(), nums.end(), 0);
        if (total % 4 != 0) return false;
        tgt = total >> 2;  // truediv 4
        sort(nums.begin(), nums.end(), greater<int>());  // big to small
        if (nums[0] > tgt) return false;
        this->nums = vector<int>(nums);
        return dfs(0, 0, 0);
    }
};
