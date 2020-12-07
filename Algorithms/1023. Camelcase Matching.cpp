class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        size_t const n = pattern.length();
        vector<bool> ans;
        for (string const& query : queries) {
            size_t const m = query.length();
            size_t j = 0;  // on pattern
            bool ok = true;
            for (size_t i = 0; i < m; ++i) {
                if (query[i] == pattern[j]) {
                    ++j;
                } else {
                    if (query[i] < 'a') {  // should have a "||" but we know they're A-Z
                        ok = false;
                        break;
                    }
                }
            }
            if (j != n) ok = false;
            ans.push_back(ok);
        }
        return ans;
    }
};
