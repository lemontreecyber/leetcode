class Solution {
    static int n_digits(int x) {
        int ans = 1;
        while (x >= 10) {
            x /= 10;
            ++ans;
        }
        return ans;
    }
   
    static void push(vector<int>& to, vector<int> const& from, int low, int high) {
        if (from.size() == 0 || low > from.back()) return;
        auto lb = (from[0] >= low) ? from.begin() : \
                  lower_bound(from.begin(), from.end(), low);
        auto ub = from.end();
        if (high < from.back()) {
            ub = upper_bound(from.begin(), from.end(), high);
            while (*ub < high) ++ub;
        }
        to.insert(to.end(), lb, ub);
    }
   
public:
    vector<int> countSteppingNumbers(int low, int high) {
        int const low_nd = n_digits(low);
        int const high_nd = n_digits(high);
        vector<int> ans;
        if (low == 0) ans.push_back(0);
        vector<int> dp{1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int nd = 1; nd <= high_nd; ++nd) {
            if (nd > 1) {
                vector<int> newdp;
                for (int i : dp) {
                    if (nd == high_nd && i * 9 > high) break;
                    int const last = i % 10;
                    if (last >= 1) newdp.push_back(i * 10 + last - 1);
                    if (last <= 8) newdp.push_back(i * 10 + last + 1);
                }
                dp = move(newdp);
            }
            push(ans, dp, low, high);
        }
        return ans;
    }
};
