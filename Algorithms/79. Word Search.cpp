class Solution {
    constexpr static char WALL = '#';
    constexpr static int DIRS[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
   
public:
    bool exist(vector<vector<char>>& board, string word) {
        size_t l = word.length();
        if (l == 0) return true;
        size_t const m = board.size();
        if (m == 0) return false;
        size_t const n = board[0].size();
        if (n == 0) return false;
        for (size_t i = 0; i < m; ++i) {
            board[i].insert(board[i].begin(), WALL);
            board[i].push_back(WALL);
        }
        board.insert(board.begin(), vector<char>(n + 2, WALL));
        board.push_back(vector<char>(n + 2, WALL));
        vector<vector<bool>> used(m + 2, vector<bool>(n + 2));
        function<bool(size_t, size_t, size_t)> dfs = [&](size_t pw, size_t i, size_t j) {
            if (pw == l) return true;
            for (auto const& [di, dj] : DIRS) {
                if (!used[i + di][j + dj] && word[pw] == board[i + di][j + dj]) {
                    used[i + di][j + dj] = true;
                    if (dfs(pw + 1, i + di, j + dj)) return true;
                    used[i + di][j + dj] = false;
                }
            }
            return false;
        };
        for (size_t i = 1; i <= m; ++i)
            for (size_t j = 1; j <= n; ++j)
                if (word[0] == board[i][j]) {
                    used[i][j] = true;
                    if (dfs(1, i, j)) return true;
                    used[i][j] = false;
                }
        return false;
    }
};

