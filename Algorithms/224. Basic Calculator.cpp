class Solution {
public:
    int calculate(string s) {
        stack<pair<int, int>> mem{{{1, 0}}};  // <sign, result>
        int sign = 1, num = 0;
        for (char c : s) {
            if (c == '(') {
                mem.top().second += sign * num;
                mem.emplace(sign, 0);
                sign = 1; num = 0;
            } else if (c == ')') {
                mem.top().second += sign * num;
                sign = 1; num = 0;
                auto [psign, pnum] = mem.top();
                mem.pop();
                mem.top().second += psign * pnum;
            } else if (c == '+') {
                mem.top().second += sign * num;
                sign = 1; num = 0;
            } else if (c == '-') {
                mem.top().second += sign * num;
                sign = -1; num = 0;
            } else if (c >= '0' && c <= '9') {
                num = num * 10 + static_cast<int>(c - '0');
            }
        }
        mem.top().second += sign * num;
        return mem.top().second;
    }
};
