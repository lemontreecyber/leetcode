class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        size_t len = beginWord.length();
        unordered_set<string> dict(wordList.begin(), wordList.end());
        unordered_map<string, unordered_set<string>> parents;
        if (dict.find(endWord) == dict.end()) return vector<vector<string>>();
        dict.erase(endWord);
        // forward search
        queue<pair<string, int>> bfs;
        bfs.emplace(beginWord, 1);
        int cur_depth = 1;
        unordered_set<string> to_erase;
        bool ending = false;
        while (!bfs.empty()) {
            auto [from, depth] = bfs.front();
            bfs.pop();
            if (depth > cur_depth) {
                if (ending) break;  // we have found endWord with cur_depth
                cur_depth = depth;
                for (auto& s : to_erase) dict.erase(s);
                to_erase.clear();
            }
            string to = from;
            for (size_t i = 0; i < len; ++i) {
                char const raw = from[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == raw) continue;
                    to[i] = c;
                    if (to == endWord) {
                        ending = true;
                        parents[endWord].insert(from);
                        break;  // only oneway from a "from" to the endWord
                    }
                    if (dict.find(to) != dict.end()) {
                        bfs.emplace(to, depth + 1);
                        parents[to].insert(from);
                        to_erase.insert(to);
                    }
                }
                to[i] = raw;
            }
        }
        // backward search
        vector<vector<string>> ans;
        vector<string> link;
        function<void(string const&)> rdfs = [&](string const& str) {
            if (str == beginWord) {
                vector<string> vs(link);
                vs.push_back(str);
                reverse(vs.begin(), vs.end());
                ans.push_back(move(vs));
            } else {
                link.push_back(str);
                for (string const& next : parents[str])
                    rdfs(next);
                link.pop_back();
            }
        };
        rdfs(endWord);
        return ans;
    }
};
