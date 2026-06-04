class Solution {
public:
    vector<int> dirx = {-1, 1, 0, 0};
    vector<int> diry = {0, 0, -1, 1};

    void solve(vector<vector<char>>& board,
               string& word,
               int i,
               int j,
               bool& found,
               string& partial,
               vector<vector<bool>>& vis)
    {
        if (found)
            return;

        if (partial.size() > word.size())
            return;

        if (partial != word.substr(0, partial.size()))
            return;

        if (partial == word)
        {
            found = true;
            return;
        }

        for (int k = 0; k < 4; k++)
        {
            int ni = i + dirx[k];
            int nj = j + diry[k];

            if (ni >= 0 && ni < board.size() &&
                nj >= 0 && nj < board[0].size() &&
                !vis[ni][nj])
            {
                vis[ni][nj] = true;
                partial.push_back(board[ni][nj]);

                solve(board, word, ni, nj,
                      found, partial, vis);

                partial.pop_back();
                vis[ni][nj] = false;
            }
        }
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] != word[0])
                    continue;

                vector<vector<bool>> vis(
                    m,
                    vector<bool>(n, false)
                );

                string partial;
                partial.push_back(board[i][j]);

                vis[i][j] = true;

                bool found = false;

                solve(board, word, i, j,
                      found, partial, vis);

                if (found)
                    return true;
            }
        }

        return false;
    }
};