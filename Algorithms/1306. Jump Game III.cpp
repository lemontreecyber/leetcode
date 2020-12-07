class Solution {
    static inline void safe_push(stack<int>& s, vector<char>& v, int x, size_t n) {
        if (x >= 0 && x < n && !v[x]) {
            s.push(x);
            v[x] = 1;
        }
    }
   
public:
    bool canReach(vector<int>& arr, int start) {
        size_t const n = arr.size();
        vector<char> v(n);  // visited
        stack<int> dfs;
        dfs.push(start);
        v[start] = 1;
        while (!dfs.empty()) {
            int i = dfs.top();
            dfs.pop();
            if (arr[i] == 0) return true;
            safe_push(dfs, v, i - arr[i], n);
            safe_push(dfs, v, i + arr[i], n);
        }
        return false;
    }
};

