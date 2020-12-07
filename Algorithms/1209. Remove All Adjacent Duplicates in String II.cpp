class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<char, int>> cnt;
        for (char c : s) {
            if (!cnt.empty() && cnt.back().first == c) {
                if (++cnt.back().second == k)
                    cnt.pop_back();
            } else {
                cnt.emplace_back(c, 1);
            }
        }
        string ans;
        for (auto [c, i] : cnt) {
            ans.append(i, c);
        }
        return ans;
    }
};
