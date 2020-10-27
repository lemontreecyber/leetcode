class Solution {
    inline void putmax(vector<int>& arr, size_t pos, int val) {
        if (arr[pos] <= val) arr[pos] = val;
    }
   
public:
    int tallestBillboard(vector<int>& rods) {
        // int const M = 5000;  // max sum
        // int const HM = (M + 2) / 2;  // max difference
        size_t const n = rods.size();
        int const total = accumulate(rods.begin(), rods.end(), 0);
        int const HM = (total + 2) >> 1;  // max difference
        if (n <= 1) return 0;
        vector<int> dp(HM, -1);  // dp[diff] = commom height
        for (int i = 0; i < n; ++i) {
            vector<int> ndp(HM, -1);
            int r = rods[i];
            if (r < HM)
                putmax(ndp, r, 0);  // only new rod
            for (int j = 0; j < HM; ++j) {  // j = diff
                if (dp[j] < 0)
                    continue;
                int dpj = dp[j];  // dpj = common height
                putmax(ndp, j, dpj);  // not add new rod
                if (j + r < HM)  // add to higher pile
                    putmax(ndp, j + r, dpj);
                if (j >= r) {  // add to lower pile, r <= diff
                    putmax(ndp, j - r, dpj + r);
                } else {  // add to lower pile, r > diff
                    if (r - j < HM)
                        putmax(ndp, r - j, dpj + j);
                }
            }
            dp = move(ndp);
        }
        return max(0, dp[0]);
    }
};
