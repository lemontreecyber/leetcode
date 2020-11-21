class Solution {
    static constexpr int kmod = 1e9 + 7;
    static constexpr int nhat = 40;
   
    static inline void addto(int& n, int const& a) {
        n = (n + a) % kmod;
    }
   
public:
    int numberWays(vector<vector<int>>& hats) {
        size_t const n = hats.size();
        size_t const m = 1 << n;
        vector<int> fits(nhat);
        for (size_t i = 0; i < n; ++i)
            for (int a : hats[i])
                fits[a - 1] |= 1 << i;
        vector<int> dp(m);
        dp[0] = 1;
        for (size_t ihat = 0; ihat < nhat; ++ihat) {
            vector<int> newdp(m);
            for (size_t mask = 0; mask < m; ++mask) {
                if (dp[mask] == 0) continue;
                int const dpmask = dp[mask];
                addto(newdp[mask], dpmask);
                size_t const pool = fits[ihat] & ~mask;
                for (size_t sub = 1; sub < m; sub <<= 1)
                    if ((pool | sub) == pool)
                        addto(newdp[mask | sub], dpmask);
            }
            dp = move(newdp);
        }
        return dp[m - 1];
    }
};
