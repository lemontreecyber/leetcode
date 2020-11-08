class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        size_t const n = arr.size();
        if (n == 0) return 0;
        if (n == 1) return arr[0];
        stack<int> mds;  // monotonic non-increasing stack
        int ans = 0;
        for (size_t i = 0; i < n; ++i) {
            while (!mds.empty() && arr[i] > mds.top()) {
                int const top = mds.top();
                mds.pop();
                if (mds.empty())
                    ans += top * arr[i];
                else
                    ans += top * min(arr[i], mds.top());
            }
            mds.push(arr[i]);
        }
        while (!mds.empty()) {
            int const top = mds.top();
            mds.pop();
            if (!mds.empty())
                ans += top * mds.top();
        }
        return ans;
    }
};
