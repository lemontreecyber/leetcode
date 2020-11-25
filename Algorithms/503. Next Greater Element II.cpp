class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        size_t const n = nums.size();
        stack<pair<size_t, int>> mds;  // monotonic decreasing, <index, num>
        vector<int> ans(n, -1);
        for (size_t i = 0; i < n; ++i) {
            int const ni = nums[i];
            while (!mds.empty() && mds.top().second < ni) {
                ans[mds.top().first] = ni;
                mds.pop();
            }
            mds.emplace(i, ni);
        }
        for (int ni : nums) {
            if (mds.size() <= 1) break;  // the biggest num stucks in the mds
            while (mds.top().second < ni) {  // as above, this should be safe
                ans[mds.top().first] = ni;
                mds.pop();
            }
        }
        return ans;
    }
};
