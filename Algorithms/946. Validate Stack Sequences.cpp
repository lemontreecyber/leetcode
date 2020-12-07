class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        size_t const n = pushed.size();
        if (n == 0) return popped.size() == 0;
        if (popped.size() != n) return false;
        stack<int> s;
        int ipop = 0;
        for (int x : pushed) {
            s.push(x);
            while (!s.empty() && s.top() == popped[ipop]) {
                s.pop();
                ++ipop;
            }
        }
        return s.empty() && ipop == n;
    }
};
