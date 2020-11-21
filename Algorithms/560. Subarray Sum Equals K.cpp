class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        size_t const n = nums.size();
        unordered_map<int, int> ns;  // number of sums, sum: number
        ns[0] = 1;
        int ans = 0;
        int s = 0;
        for (size_t i = 0; i < n; ++i) {
            s += nums[i];
            ans += ns[s - k];
            ++ns[s];
        }
        return ans;
    }
};
