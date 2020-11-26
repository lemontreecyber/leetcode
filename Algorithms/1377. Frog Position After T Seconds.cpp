class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> conn(n);
        for (auto const& a : edges) {
            conn[a[0] - 1].push_back(a[1] - 1);
            conn[a[1] - 1].push_back(a[0] - 1);
        }
        --target;  // 1-based -> 0-based
        double sum_prob = 0.;
        vector<char> visited(n);
        function<void(int, int, double)> dfs = [&](int vertex, int t_rem, double prob) {
            if (t_rem == 0 || conn[vertex].size() == 0) {
                if (vertex == target) sum_prob += prob;
                return;
            }
            visited[vertex] = 1;
            int candidates = 0;
            size_t i;
            for (i = 0; i < conn[vertex].size(); ++i)
                if (!visited[conn[vertex][i]]) ++candidates;
            if (candidates == 0) {
                if (vertex == target) sum_prob += prob;
            } else {
                for (i = 0; i < conn[vertex].size(); ++i)
                    if (!visited[conn[vertex][i]])
                        dfs(conn[vertex][i], t_rem - 1, prob / candidates);
            }
            visited[vertex] = 0;
        };
        dfs(0, t, 1.);
        return sum_prob;
    }
};
