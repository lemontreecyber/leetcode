class Solution {
public:
    int calculate(string s) {
        size_t const n = s.length();
        vector<int> nums;
        int cur = 0;
        char op = '+';
        for (int i = 0; i < n; ++i) {
            if (s[i] == ' ') continue;
            while (i < n && isdigit(s[i]))
                cur = cur * 10 + static_cast<int>(s[i++] - '0');
            switch (op) {
                case '+': nums.push_back(cur); break;
                case '-': nums.push_back(-cur); break;
                case '*': nums.back() *= cur; break;
                case '/': nums.back() /= cur; break;
            }
            if (i >= n) break;
            cur = 0;
            op = s[i];
        }
        return accumulate(nums.begin(), nums.end(), 0);
    }
};
