class Solution {    
public:
    bool parseBoolExpr(string expression) {
        if (expression[0] == 't') return true;
        if (expression[0] == 'f') return false;
        char const op = expression[0];
        int const end = expression.length() - 1;  // remove ')'
        int begin = 2;  // remove '#('
        if (op == '!') return !parseBoolExpr(expression.substr(begin, end - begin));
        int cnt = 0;  // count of unpaired brakets
        bool ans = (op == '&') ? true : false;\
        for (int pos = begin; pos <= end; ++pos) {
            if (pos == end || (expression[pos] == ',' && cnt == 0)) {
                bool const b = parseBoolExpr(expression.substr(begin, pos - begin));
                if (op == '&') {
                    ans = ans && b;
                    if (!ans) return false;
                } else {
                    ans = ans || b;
                    if (ans) return true;
                }
                begin = pos + 1;
            } else if (expression[pos] == '(') {
                ++cnt;
            } else if (expression[pos] == ')') {
                --cnt;
            }
        }
        return ans;
    }
};
