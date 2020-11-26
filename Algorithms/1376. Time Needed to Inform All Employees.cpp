class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> team(n);  // [i] = i's subordinates
        for (int i = 0; i < n; ++i) {
            if (i != headID)
                team[manager[i]].push_back(i);
        }
        // start traverse
        int max_time = 0;
        stack<pair<int, int>> dfs;  // <id, time to id>
        dfs.emplace(headID, 0);
        while (!dfs.empty()) {
            auto [id, time] = dfs.top();
            dfs.pop();
            max_time = max(max_time, time);
            time += informTime[id];  // not good, just to save space
            for (int sub : team[id])
                dfs.emplace(sub, time);
        }
        return max_time;
    }
};

