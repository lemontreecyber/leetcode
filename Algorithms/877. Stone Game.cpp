class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int const n = piles.size();
        if (n <= 1) return true;
        // dp[i] = max first player can win, from i-th to (i+d)-th, d = 0 now
        vector<int> dp(piles);
        for (int d = 1; d < n; ++d) {
            vector<int> newdp(n - d);
            for (int i = 0; i + d < n; ++i) {
                newdp[i] = max(
                    piles[i] - dp[i + 1],
                    piles[i + d] - dp[i]
                );
            }
            dp = move(newdp);
        }
        return dp[0] > 0;
    }
};
