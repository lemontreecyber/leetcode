class Solution {
public:
    vector<string> expand(string S) {
        if (S.length() == 0) return vector<string>();
        vector<vector<char>> ops;
        for (size_t i = 0; i < S.length(); ++i) {
            if (S[i] == '{') {
                vector<char> vec;
                ++i;
                while (S[i] != '}') {
                    if (S[i] != ',') vec.push_back(S[i]);
                    ++i;
                }
                sort(vec.begin(), vec.end());
                ops.push_back(move(vec));
            } else {
                ops.push_back({S[i]});
            }
        }
        vector<string> ans;
        function<void(string&)> dfs = [&](string& s) {
            size_t const i = s.length();
            s.push_back('#');
            if (i == ops.size() - 1) {
                for (char c : ops[i]) {
                    s[i] = c;
                    ans.push_back(s);
                }
            } else {
                for (char c : ops[i]) {
                    s[i] = c;
                    dfs(s);
                }
            }
            s.pop_back();
        };
        string s = "";
        dfs(s);
        return ans;
    }
};

