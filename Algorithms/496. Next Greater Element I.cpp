class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> mds;  // monotonic decreasing
        unordered_map<int, int> dict;
        for (int i : nums2) {
            while (!mds.empty() && i > mds.top()) {
                dict.emplace(mds.top(), i);
                mds.pop();
            }
            mds.push(i);
        }
        size_t const n = nums1.size();
        vector<int> ans(n);
        for (size_t i = 0; i < n; ++i)
            ans[i] = dict.count(nums1[i]) ? dict[nums1[i]] : -1;
        return ans;
    }
};

