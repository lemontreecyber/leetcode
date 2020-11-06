class Solution {
public:
    int minScoreTriangulation(vector<int>& A) {
        size_t const n = A.size();
        if (n < 3) return 0;  // throw
        // dp[i][j] = min score using vertexes [i, j]
        vector<vector<int>> dp(n, vector<int>(n));
        for (size_t dist = 2; dist < n; ++dist) {
            for (size_t i = 0, j = i + dist; j < n; ++i, ++j) {
                int s = INT_MAX;
                int prodij = A[i] * A[j];
                for (size_t m = i + 1; m < j; ++m)
                    s = min(s, A[m] * prodij + dp[i][m] + dp[m][j]);
                dp[i][j] = s;
            }
        }
        return dp[0][n - 1];
    }
};
