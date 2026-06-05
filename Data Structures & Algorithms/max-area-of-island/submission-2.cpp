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

    int getMaxSize()
    {
        int maxi = 0;

        for (int i = 0; i < parent.size(); i++)
        {
            if (find(i) == i)
            {
                maxi = max(maxi, sz[i]);
            }
        }

        return maxi;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        DSU dsu(m * n);

        vector<int> dx = {1, 0};
        vector<int> dy = {0, 1};

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 0)
                    continue;

                int u = i * n + j;

                for (int k = 0; k < 2; k++) {
                    int ni = i + dx[k];
                    int nj = j + dy[k];

                    if (ni < m && nj < n &&
                        grid[ni][nj] == 1)
                    {
                        int v = ni * n + nj;
                        dsu.unite(u, v);
                    }
                }
            }
        }

        int ans = 0;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
            {
                ans = max(ans, 1);

                int root = dsu.find(i*n + j);
                ans = max(ans, dsu.sz[root]);
            }
        }
    }

    return ans;
    }
};
