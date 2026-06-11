class Solution {
public:
    vector<int> dirx = {0, 0, -1, 1};
    vector<int> diry = {-1, 1, 0, 0};

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));

        dist[0][0] = 0;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto cur = pq.top();
            pq.pop();

            int effort = cur[0];
            int row = cur[1];
            int col = cur[2];

            if (effort > dist[row][col])
                continue;

            if (row == m - 1 && col == n - 1)
                return effort;

            for (int k = 0; k < 4; k++) {
                int nr = row + dirx[k];
                int nc = col + diry[k];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n)
                    continue;

                int newEffort = max(
                    effort,
                    abs(heights[row][col] - heights[nr][nc])
                );

                if (newEffort < dist[nr][nc]) {
                    dist[nr][nc] = newEffort;
                    pq.push({newEffort, nr, nc});
                }
            }
        }

        return 0;
    }
};