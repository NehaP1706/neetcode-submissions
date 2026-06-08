class Solution {
public:
    int m, n;
    vector<vector<int>> dp;
    vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    int dfs(int r, int c, vector<vector<int>>& matrix)
    {
        if (dp[r][c] != -1)
            return dp[r][c];

        dp[r][c] = 1;

        for (auto& d : dirs)
        {
            int nr = r + d[0];
            int nc = c + d[1];

            if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                continue;

            if (matrix[nr][nc] > matrix[r][c])
            {
                dp[r][c] = max(dp[r][c], 1 + dfs(nr, nc, matrix));
            }
        }

        return dp[r][c];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        dp.assign(m, vector<int>(n, -1));

        int ans = 0;

        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ans = max(ans, dfs(i, j, matrix));
            }
        }

        return ans;
    }
};