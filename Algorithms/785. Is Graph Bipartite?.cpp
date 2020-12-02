class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        size_t const n = graph.size();
        if (n <= 1) return true;
        size_t visited = 0;
        vector<int> color(n);
        queue<int> bfs;
        while (visited < n) {
            if (!bfs.empty()) {
                int const i = bfs.front();
                bfs.pop();
                int nc = color[i] == 1 ? 2 : 1;  // the neighbors' color
                for (int j : graph[i]) {
                    if (color[j] == 0) {
                        color[j] = nc;
                        bfs.push(j);
                    } else if (color[j] != nc) {
                        return false;
                    }
                }
                ++visited;
            } else {
                for (size_t i = 0; i < n; ++i)
                    if (color[i] == 0) {
                        color[i] = 1;
                        bfs.push(i);
                        break;
                    }
            }
        }
        return true;
    }
};

