class Solution {
public:
    bool canDistribute(vector<int>& nums, vector<int>& quantity) {
        unordered_map<int, int> numcnt;
        for (int a : nums) ++numcnt[a];
        vector<int> cnts;
        for (auto const& [a, c] : numcnt) cnts.push_back(c);
        size_t const nc = cnts.size();
        size_t const nq = quantity.size();
        size_t const mq = 1 << nq;
        vector<int> sumq(mq);
        for (size_t i = 0; i < nq; ++i) {
            int const qi = quantity[i];
            size_t const mi = 1 << i;
            for (size_t j = 0; j < mi; ++j)
                sumq[j + mi] = sumq[j] + qi;
        }
        vector<bool> dp(mq);
        dp[0] = true;
        for (size_t i = 0; i < nc; ++i) {
            vector<bool> newdp(mq);
            for (size_t mask = 0; mask < mq; ++mask) {
                if (!dp[mask]) continue;
                newdp[mask] = true;
                size_t const pool = mq - 1 ^ mask;
                for (size_t sub = pool; sub; sub = sub - 1 & pool) {
                    if (sumq[sub] <= cnts[i])
                        newdp[mask | sub] = true;
                }
            }
            dp = move(newdp);
        }
        return dp[mq - 1];
    }
};
