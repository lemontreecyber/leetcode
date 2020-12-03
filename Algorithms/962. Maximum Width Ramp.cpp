class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        size_t const n = A.size();
        stack<int> mds;  // of indice, A[index] monotic desc
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            if (mds.empty() || A[mds.top()] > A[i])
                mds.push(i);
        }
        for (int i = n - 1; i >= 0; --i) {
            while (!mds.empty() && A[mds.top()] <= A[i]) {
                ans = max(ans, i - mds.top());
                mds.pop();
            }
        }
        return ans;
    }
};
