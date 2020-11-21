class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        size_t const n = s.size();
        size_t const m = wordDict.size();
        if (n == 0 || m == 0) return false;
        vector<size_t> l(m);
        for (size_t i = 0; i < m; ++i)
            l[i] = wordDict[i].size();
        vector<bool> can(n, false);
        can[0] = true;
        for (size_t i = 0; i < n; ++i) {
            if (!can[i]) continue;
            for (size_t j = 0; j < m; ++j) {
                size_t const to = i + l[j];
                if (to > n || can[to]) continue;
                if (s.substr(i, l[j]) == wordDict[j]) {
                    if (to == n) return true;
                    can[to] = true;
                }
            }
        }
        return false;
    }
};

