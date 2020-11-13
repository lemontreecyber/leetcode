class Solution {
    bool compatible(int a, int b, size_t n) {
        if (n <= 1) return true;
        if (a & 1 && b & 2) return false;
        if (a & 1 << n - 1 && b & 1 << n - 2) return false;
        for (size_t i = 1; i < n - 1; ++i) {
            if (a & 1 << i && (b & 1 << i - 1 || b & 1 << i + 1))
                return false;
        }
        return true;
    }
   
public:
    int maxStudents(vector<vector<char>>& seats) {
        size_t const m = seats.size();
        if (m == 0) return 0;
        size_t const n = seats[0].size();
        if (n == 0) return 0;
        size_t const N = 1 << n;
        vector<int> cnts(N);  // count of bit 1's in a rowmask
        for (size_t i = 1; i < N; ++i)
            cnts[i] = (i & 1) + cnts[i >> 1];
        vector<pair<int, int>> dp;  // <mask, max total>
        for (size_t row = 0; row < m; ++row) {
            int rowmask = 0;
            for (size_t i = 0; i < n; ++i)
                if (seats[row][i] == '.')
                    rowmask |= 1 << i;
            vector<pair<int, int>> newdp;
            for (int mask = 0; mask < N; ++mask) {
                if ((mask | rowmask) != rowmask) continue;
                if (compatible(mask, mask, n)) {
                    int prev = 0;
                    for (auto& a : dp) {
                        if (prev < a.second && compatible(mask, a.first, n))
                            prev = a.second;
                    }
                    newdp.emplace_back(mask, prev + cnts[mask]);
                }
            }
            dp = move(newdp);
        }
        int ans = 0;
        for (auto& a : dp)
            ans = max(ans, a.second);
        return ans;
    }
};
