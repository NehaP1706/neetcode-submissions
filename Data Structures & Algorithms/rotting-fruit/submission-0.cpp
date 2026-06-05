class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int ROWS = grid.size();
        int COLS = grid[0].size();

        queue<pair<int,int>> q;
        int fresh = 0;

        for (int r = 0; r < ROWS; r++) {
            for (int c = 0; c < COLS; c++) {
                if (grid[r][c] == 2)
                    q.push({r,c});
                else if (grid[r][c] == 1)
                    fresh++;
            }
        }

        if (fresh == 0)
            return 0;

        vector<vector<int>> dir = {
            {1,0}, {-1,0}, {0,1}, {0,-1}
        };

        int minutes = 0;

        while (!q.empty() && fresh > 0) {
            int sz = q.size();

            for (int i = 0; i < sz; i++) {
                auto [r,c] = q.front();
                q.pop();

                for (auto& d : dir) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nr < ROWS &&
                        nc >= 0 && nc < COLS &&
                        grid[nr][nc] == 1)
                    {
                        grid[nr][nc] = 2;
                        fresh--;

                        q.push({nr,nc});
                    }
                }
            }

            minutes++;
        }

        return fresh == 0 ? minutes : -1;
    }
};