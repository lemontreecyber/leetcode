class Solution {
public:
    string simplifyPath(string path) {
        vector<string> hier;
        for (size_t i = 0, j = path.find('/'); ; i = j + 1, j = path.find('/', i)) {
            string w = path.substr(i, j - i);
            if (w == "..") {
                if (!hier.empty()) hier.pop_back();
            } else if (w != ".") {
                if (w.length() > 0) hier.push_back(move(w));
            }
            if (j == string::npos) break;
        }
        if (hier.empty()) return "/";
        string ans = "";
        for (auto const& w : hier) {
            ans.push_back('/');
            ans.append(w);
        }
        return ans;
    }
};
