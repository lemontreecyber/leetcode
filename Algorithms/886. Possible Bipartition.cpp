class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        if (N <= 2) return true;
        vector<vector<int>> conn(N);
        for (auto const& a : dislikes) {
            conn[a[0] - 1].push_back(a[1] - 1);
            conn[a[1] - 1].push_back(a[0] - 1);
        }
        int visited = 0;
        vector<int> color(N);  // 0 = unvisited, 1 = red, -1 = black
        queue<int> bfs;
        while (visited < N) {
            if (!bfs.empty()) {
                int const i = bfs.front();
                bfs.pop();
                ++visited;
                int const nc = -color[i];  // color of neighbor
                for (int j : conn[i]) {
                    if (color[j] == 0) {
                        color[j] = nc;
                        bfs.push(j);
                    } else {
                        if (color[j] != nc) return false;
                    }
                }
            }
            if (bfs.empty()) {
                for (int i = 0; i < N; ++i)
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
