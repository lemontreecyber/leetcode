class Solution {
public:
    int minStickers(vector<string>& stickers, string target) {
        size_t const n = target.size();
        size_t const m = 1 << n;
        vector<int> dp(m, INT_MAX);
        dp[0] = 0;
        for (size_t mask = 0; mask < m; ++mask) {
            if (dp[mask] == INT_MAX) continue;
            for (string& s : stickers) {
                size_t next = mask;
                for (char c : s) {
                    for (size_t i = 0; i < n; ++i) {
                        if (c == target[i] && !(next >> i & 1)) {
                            next |= 1 << i;
                            break;
                        }
                    }
                }
                dp[next] = min(dp[next], dp[mask] + 1);
            }
        }
        return dp[m - 1] == INT_MAX ? -1 : dp[m - 1];
    }
};

