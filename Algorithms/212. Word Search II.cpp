class Solution {
    constexpr static char WALL = '#';
    constexpr static int NEIGHBORS[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
   
    static bool search(vector<vector<char>> const& board, vector<vector<bool>>& used, string const& word, size_t pos, size_t i, size_t j) {
        if (pos == word.length()) return true;
        for (auto const& [di, dj] : NEIGHBORS)
            if (!used[i + di][j + dj] && board[i + di][j + dj] == word[pos]) {
                used[i + di][j + dj] = true;
                if (search(board, used, word, pos + 1, i + di, j + dj))
                    return true;
                used[i + di][j + dj] = false;
            }
        return false;
    }
   
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        size_t const m = board.size();
        if (m == 0) return vector<string>();
        size_t const n = board[0].size();
        if (n == 0) return vector<string>();
        for (size_t i = 0; i < m; ++i) {
            board[i].insert(board[i].begin(), WALL);
            board[i].push_back(WALL);
        }
        board.insert(board.begin(), vector<char>(n + 2, WALL));
        board.push_back(vector<char>(n + 2, WALL));
        // start
        vector<string> ans;
        for (string& word : words) {
            if (word.length() == 0) {
                ans.push_back(word);
                continue;
            }
            bool hit = false;
            for (size_t i = 1; i <= m; ++i) {
                if (hit) break;
                for (size_t j = 1; j <= n; ++j)
                    if (board[i][j] == word[0]) {
                        vector<vector<bool>> used(m + 2, vector<bool>(n + 2));
                        used[i][j] = true;
                        if (search(board, used, word, 1, i, j)) {
                            hit = true;
                            break;
                        }
                    }
            }
            if (hit) ans.push_back(word);
        }
        return ans;
    }
};
