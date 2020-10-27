class Solution {
    size_t n;
    int total;
   
    inline bool eqavg(int cnt, int sum) {
        // return if sum / cnt == total / n
        return sum * (n - cnt) == (total - sum) * cnt;
    }
   
    inline bool mktrue(vector<vector<bool>>& dp, size_t i, size_t j) {
        // i = cnt, j = sum, assign dp[i][j] <= true
        // return if j / i == total / n, i == n safe
        if (dp[i][j]) return false;  // must have checked before
        dp[i][j] = true;
        return (i != n) && eqavg(i, j);
    }
   
public:
    bool splitArraySameAverage(vector<int>& A) {
        n = A.size();
        if (n < 2) return false;
        sort(A.begin(), A.end());
        total = accumulate(A.begin(), A.end(), 0);
        vector<vector<bool>> dp(n + 1, vector<bool>(total + 1));
        int upto = A[0];
        if (eqavg(1, A[0])) return true;
        dp[1][A[0]] = true;
        for (size_t pos = 1; pos < n; ++pos) {
            int Apos = A[pos];
            vector<vector<bool>> newdp(n + 1, vector<bool>(total + 1));
            if (mktrue(newdp, 1, Apos)) return true;
            for (size_t i = 0; i < pos + 1; ++i) {
                for (size_t j = 0; j < upto + 1; ++j) {
                    if (!dp[i][j]) continue;
                    newdp[i][j] = true;
                    if (mktrue(newdp, i + 1, j + Apos)) return true;
                }
            }
            upto += Apos;
            dp = move(newdp);
        }
        return false;
    }
};
