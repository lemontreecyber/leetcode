class Solution {
    void construct(vector<string>& ans, vector<string>& wd, vector<vector<pair<size_t, size_t>>> const& bl, size_t j, string const& sub) {
        for (auto const& p : bl[j]) {
            if (p.second == 0) {
                ans.push_back(wd[p.first] + sub);
            } else {
                construct(ans, wd, bl, p.second, ' ' + wd[p.first] + sub);
            }
        }
    }
   
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        size_t n = s.size();
        size_t m = wordDict.size();
        vector<size_t> l(m);
        for (size_t i = 0; i < m; ++i)
            l[i] = wordDict[i].size();
        vector<vector<pair<size_t, size_t>>> bl(n + 1);  // back link, <iword, jback>
        bl[0].push_back({0, 0});  // dummy
        for (size_t j = 0; j < n; ++j) {
            if (bl[j].size() == 0)
                continue;
            for (size_t i = 0; i < m; ++i) {
                if (j + l[i] <= n && s.substr(j, l[i]) == wordDict[i])
                    bl[j + l[i]].push_back({i, j});
            }
        }
        vector<string> ans;
        construct(ans, wordDict, bl, n, "");
        return ans;
    }
};
