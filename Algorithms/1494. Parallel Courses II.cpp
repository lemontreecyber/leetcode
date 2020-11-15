class Solution {
    inline void minimize(int& num, int other) {
        if (num > other) num = other;
    }
   
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& dependencies, int k) {
        /* prepare */
        int const m = 1 << n;
        vector<int> pre(n);  // pre[i] = the mask of all prerequisites of i
        for (auto const& a : dependencies)
            pre[a[1] - 1] |= 1 << a[0] - 1;
        /* dp */
        vector<int> dp(m, INT_MAX);  // semesters toword mask = i
        dp[0] = 0;
        for (int mask = 0; mask < m; ++mask) {
            if (dp[mask] == INT_MAX) continue;
            int pool = 0;  // all the courses can be elected
            for (int i = 0; i < n; ++i)
                if ((mask | pre[i]) == mask)
                    pool |= 1 << i;
            pool &= ~mask;  // do not elect twice
            int toelect = pool;
            for (int toelect = pool; toelect != 0; toelect = (toelect - 1) & pool) {  // next subset of pool
                if (__builtin_popcount(toelect) <= k)
                    minimize(dp[mask | toelect], dp[mask] + 1);
            }
        }
        return dp[m - 1];
    }
};
