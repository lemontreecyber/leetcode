class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        size_t const n = nums.size();
        set<vector<int>> ans;
        function<void(vector<int>&, size_t)> dfs = [&](vector<int>& vec, size_t i) {
            if (i == n) {
                if (vec.size() >= 2) ans.insert(vec);
                return;
            }
            dfs(vec, i + 1);
            if (vec.empty() || vec.back() <= nums[i]) {
                vec.push_back(nums[i]);
                dfs(vec, i + 1);
                vec.pop_back();
            }
        };
        vector<int> vec;
        dfs(vec, 0);
        return vector<vector<int>>(ans.begin(), ans.end());
    }
};
