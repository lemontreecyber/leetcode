class Solution {
public:
    string removeKdigits(string num, int k) {
        size_t const n = num.length();
        string ans;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            char const numi = num[i];
            while (cnt < k && !ans.empty() && ans.back() > numi) {
                ans.pop_back();
                ++cnt;
            }
            if (!ans.empty() || numi != '0')
                ans.push_back(numi);
        }
        for (; cnt < k && !ans.empty(); ++cnt) ans.pop_back();
        return ans.empty() ? "0" : ans;
    }
};
