class Solution {
public:
    int rob (vector<int>& nums) {
        int len = nums.size ();
        if (len <= 0) { return 0; }
        if (len == 1) { return nums[0]; }
        vector<int> values (len, 0);
        values[0] = nums[0];
        values[1] = max (nums[0], nums[1]);
        for (int i = 2; i < len; i++) {
            values[i] = max (values[i - 1], nums[i] + values[i - 2]);
        }
        return values[len - 1];
    }
};
