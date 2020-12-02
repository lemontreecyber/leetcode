class Solution {
public:
    int maxUniqueSplit(string s) {
        string_view const sv(s);
        size_t const n = s.length();
        unordered_set<string_view> dict;
        int const m = 1 << n - 1;
        int ans = 0;
        for (int mask = 0; mask < m; ++mask){
            if (__builtin_popcount(mask) + 1 <= ans) continue;
            dict.clear();
            bool valid = true;
            int last = 0;
            for (int i = 0; i < n && valid; ++i) {
                if ((1 << i) & mask || i == n - 1) {
                    valid &= dict.insert(sv.substr(last, i - last + 1)).second;
                    last = i + 1;
                }
            }
            if (valid) ans = max(ans, static_cast<int>(dict.size()));
        }
        return ans;
    }
};

