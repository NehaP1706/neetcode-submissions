class Solution {
private:
    vector<vector<int>> adj;

    int dfs(int node, int parent) {
        int hgt = 0;
        for (int nei : adj[node]) {
            if (nei == parent)
                continue;
            hgt = max(hgt, 1 + dfs(nei, node));
        }
        return hgt;
    }

public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        int minHgt = n;
        vector<int> result;
        for (int i = 0; i < n; i++) {
            int curHgt = dfs(i, -1);
            if (curHgt == minHgt) {
                result.push_back(i);
            } else if (curHgt < minHgt) {
                result = {i};
                minHgt = curHgt;
            }
        }
        return result;
    }
};