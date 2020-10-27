class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        size_t n = stones.size();
        if (n == 0) return 0;
        // dp init  // dp[weight]
        int ul = stones[0];  // upper limit of j
        auto dp = new vector<bool>(ul + 1);
        (*dp)[ul] = true;
        // dp aggr
        for (size_t i = 1; i < n; ++i) {
            int new_ul = ul + stones[i];
            auto new_dp = new vector<bool>(new_ul + 1);
            for (int j = 0; j <= ul; ++j) {
                if ((*dp)[j]) {
                    (*new_dp)[j + stones[i]] = true;
                    (*new_dp)[abs(j - stones[i])] = true;
                }
            }
            ul = new_ul;
            delete dp;
            dp = new_dp;
        }
        // ans
        int ans = -1;
        for (int j = 0; j <= ul; ++j)
            if ((*dp)[j]) {
                ans = j;
                break;
            }
        delete dp;
        return ans;
    }
};
