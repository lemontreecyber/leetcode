class Solution {
public:
    int calculate(string s) {
        int const n = s.length();
        vector<long> nums;
        long cur = 0;
        char op = '+';
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            if (s[i] == '(') {
                int j = i + 1;
                for (int cnt = 1; cnt > 0; ++j) {
                    if (s[j] == '(') ++cnt;
                    if (s[j] == ')') --cnt;
                }  // now j is (the pos of target ')') + 1
                cur = calculate(s.substr(i + 1, j - 2 - i));
                i = j;
            } else {
                cur = 0;
                while (i < n && isdigit(s[i]))
                    cur = cur * 10 + static_cast<long>(s[i++] - '0');
            }
            switch (op) {
                case '+': nums.push_back(cur); break;
                case '-': nums.push_back(-cur); break;
                case '*': nums.back() *= cur; break;
                case '/': nums.back() /= cur; break;
            }
            if (i >= n) break;
            op = s[i];
        }
        return static_cast<int>(accumulate(nums.begin(), nums.end(), 0));
    }
};
