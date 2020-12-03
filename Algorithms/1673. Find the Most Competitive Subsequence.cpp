class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        // if (k == 0) return vector<int>(nums);
        k = nums.size() - k;
        vector<int> ans;
        for (int x : nums) {
            while (k > 0 && !ans.empty() && ans.back() > x) {
                ans.pop_back();
                --k;
            }
            ans.push_back(x);
        }
        for (; k > 0; --k) ans.pop_back();
        return ans;
    }
};
