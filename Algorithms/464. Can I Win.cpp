class Solution {
    size_t m;  // maxChoosableInteger
    // dp[state] = state is known that current player will win/lose
    // state is a mask where the i-th bit is 1 means that choice is taken
    vector<bool> win, lose;  
   
    bool dfs(size_t state, int desired) {
        if (desired <= 0) return false;
        if (win[state]) return true;
        if (lose[state]) return false;
        for (size_t i = 0; i < m; ++i) {  // i-th has the value of i+1
            if ((state & (1 << i)) > 0) continue;  // i-th has been taken
            // if after taking i-th, the next player cannot win, this player wins
            if (!dfs(state | (1 << i), desired - i - 1)) {
                win[state] = true;
                return true;
            }
        }
        lose[state] = true;
        return false;
    }
   
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        m = maxChoosableInteger;
        if (desiredTotal <= 0) return true;
        if (desiredTotal > m * (m + 1) / 2) return false;
        win = vector<bool>(1 << m);
        lose = vector<bool>(1 << m);    
        return dfs(0, desiredTotal);  // initial state = 0
    }
};
