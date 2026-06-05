class DSU {
public:
    vector<int> parent, sz;

    DSU(int n) {
        parent.resize(n);
        sz.resize(n, 1);

        for (int i = 0; i < n; i++)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] == x)
            return x;

        return parent[x] = find(parent[x]);
    }

    void unite(int a, int b) {
        a = find(a);
        b = find(b);

        if (a == b)
            return;

        if (sz[a] < sz[b])
            swap(a, b);

        parent[b] = a;
        sz[a] += sz[b];
    }
};

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();

        DSU dsu(m * n + 1);

        int dummy = m * n;

        auto id = [&](int r, int c) {
            return r * n + c;
        };

        vector<pair<int,int>> dirs = {
            {1,0},
            {-1,0},
            {0,1},
            {0,-1}
        };

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] != 'O')
                    continue;

                if (r == 0 || r == m-1 ||
                    c == 0 || c == n-1)
                {
                    dsu.unite(id(r,c), dummy);
                }

                for (auto& [dr, dc] : dirs) {
                    int nr = r + dr;
                    int nc = c + dc;

                    if (nr >= 0 && nr < m &&
                        nc >= 0 && nc < n &&
                        board[nr][nc] == 'O')
                    {
                        dsu.unite(
                            id(r,c),
                            id(nr,nc)
                        );
                    }
                }
            }
        }

        int borderRoot = dsu.find(dummy);

        for (int r = 0; r < m; r++) {
            for (int c = 0; c < n; c++) {

                if (board[r][c] == 'O' &&
                    dsu.find(id(r,c)) != borderRoot)
                {
                    board[r][c] = 'X';
                }
            }
        }
    }
};