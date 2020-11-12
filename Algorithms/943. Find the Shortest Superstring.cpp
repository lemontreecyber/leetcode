class Solution {
public:
    string shortestSuperstring(vector<string>& A) {
        size_t const n = A.size();
        size_t const m = 1 << n;
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));  // length[mask][tail]
        vector<vector<int>> lasttail(m, vector<int>(n, -1));  // last tail
        vector<vector<int>> comm(n, vector<int>(n)); // i concat j
        vector<size_t> sizes(n);
        for (size_t i = 0; i < n; ++i)
            sizes[i] = A[i].size();
        for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
        if (i == j) continue;
        for (size_t k = min(sizes[i], sizes[j]); k > 0; --k) {
        if (A[i].substr(sizes[i] - k) == A[j].substr(0, k)) {
        comm[i][j] = k;
        break;
        }
        }
        }
        }
        for (size_t i = 0; i < n; ++i)
            dp[1 << i][i] = sizes[i];
        for (size_t mask = 1; mask < m; ++mask) {
        for (int j = 0; j < n; ++j) {  // tail
                size_t const mj = 1 << j;
        if ((mask & mj) == 0) continue;  // illegal
                int& mindp = dp[mask][j];
                int& minlast = lasttail[mask][j];
        for (int i = 0; i < n; ++i) {  // last tail
        if (i == j || (mask & (1 << i)) == 0) continue;  // no in
                    int const curdp = dp[mask ^ mj][i] + sizes[j] - comm[i][j];
                    if (curdp < mindp) {
                        mindp = curdp;
                        minlast = i;
                    }
                }
        }
        }
        size_t minlen = dp[m - 1][0];
        int tail = 0;
        for (size_t i = 1; i < n; ++i) {
        if (dp[m - 1][i] < minlen) {
                tail = i;
                minlen = dp[m - 1][i];
            }
        }
        string ans = A[tail];
        size_t mask = m - 1;
        int last = lasttail[mask][tail];
        while (last >= 0) {
            ans = A[last].substr(0, A[last].length() - comm[last][tail]) + ans;
            mask ^= 1 << tail;
            tail = last;
            last = lasttail[mask][tail];
        }
        return ans;
    }
};
