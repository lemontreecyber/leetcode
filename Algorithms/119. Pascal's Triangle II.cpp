class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> dp{1};
        for (int i = 0; i < rowIndex; ++i) {
            dp.push_back(1);
            for (int j = i; j >= 1; --j)
                dp[j] += dp[j - 1];
        }
        return dp;
    }
};
