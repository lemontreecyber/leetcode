class Solution {
public:
    bool wordPatternMatch(string pattern, string s) {
        size_t const lenp = pattern.length();
        size_t const lens = s.length();
        vector<string> dict(26);
        unordered_set<string> pool;
        function<bool(size_t, size_t)> match = [&](size_t posp, size_t poss) {
            if (posp == lenp && poss == lens) return true;
            if (posp == lenp || poss == lens) return false;
            string& word = dict[pattern[posp] - 'a'];
            if (word.length() > 0) {
                if (word != s.substr(poss, word.length())) return false;
                return match(posp + 1, poss + word.length());
            } else {
                for (size_t l = 1; poss + l <= s.length(); ++l) {
                    word = s.substr(poss, l);
                    if (pool.find(word) == pool.end()) {
                        pool.insert(word);
                        if (match(posp + 1, poss + l)) return true;
                        pool.erase(word);
                    }
                    word = "";
                }
            }
            return false;
        };
        return match(0, 0);
    }
};
