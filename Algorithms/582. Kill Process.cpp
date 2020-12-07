class Solution {
public:
    vector<int> killProcess(vector<int>& pid, vector<int>& ppid, int kill) {
        unordered_map<int, vector<int>> children;
        size_t const n = pid.size();
        for (size_t i = 0; i < n; ++i)
            children[ppid[i]].push_back(pid[i]);
        vector<int> ans = {kill};
        stack<int> dfs;
        dfs.push(kill);
        while (!dfs.empty()) {
            int const cur = dfs.top();
            dfs.pop();
            for (int i : children[cur]) {
                ans.push_back(i);
                dfs.push(i);
            }
        }
        return ans;
    }
};
