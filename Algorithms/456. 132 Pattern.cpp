class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) return false;
        stack<int> mis;
        int r = INT_MIN;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int const ni = nums[i];
            if (ni < r) return true;
            while (!mis.empty() && mis.top() < ni) {
                r = max(r, mis.top());
                mis.pop();
            }
            mis.push(ni);
        }
        return false;
    }
};
