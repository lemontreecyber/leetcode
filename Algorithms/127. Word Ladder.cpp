class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        size_t const len = beginWord.length();
        unordered_set dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) return 0;
        dict.erase(endWord);
        queue<pair<string, int>> bfs;
        bfs.emplace(beginWord, 1);
        while (!bfs.empty()) {
            auto [s, d] = bfs.front();
            bfs.pop();
            for (size_t i = 0; i < len; ++i) {
                char const raw = s[i];
                for (char c = 'a'; c <= 'z'; ++c) {
                    if (c == raw) continue;
                    s[i] = c;
                    if (s == endWord) return d + 1;
                    if (dict.find(s) != dict.end()) {
                        bfs.emplace(s, d + 1);
                        dict.erase(s);
                    }
                }
                s[i] = raw;
            }
        }
        return 0;
    }
};
