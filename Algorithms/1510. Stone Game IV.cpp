class Solution {
    inline int isqrt(int n) {
        return static_cast<int>(floor(sqrt(static_cast<double>(n))));
    }
   
public:
    bool winnerSquareGame(int n) {
        int const np = isqrt(n);
        vector<int> piles(np);
        for (int i = 0; i < np; ++i)
            piles[i] = (i + 1) * (i + 1);
        vector<bool> solved(n + 1);
        vector<bool> win(n + 1);  // dp[i] = first player can win when n = i
        solved[0] = true; solved[1] = true;
        win[0] = false; win[1] = true;
        function<bool(int)> dfs = [&](int now) {
            if (solved[now]) return win[now];
            solved[now] = true;
            for (int j = isqrt(now) - 1; j >= 0; --j) {
                if (dfs(now - piles[j]) == false)
                    return win[now] = true;
            }
            return win[now] = false;
        };
        return dfs(n);
    }
};
