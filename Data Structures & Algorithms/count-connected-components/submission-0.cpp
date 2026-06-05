class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for (int x : adj[node])
        {
            if (!vis[x])
            {
                dfs(x, adj, vis);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
        int m = edges.size();

        vector<vector<int>> adj (n);

        for (int i=0; i<m; i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);
        int count = 0;

        for (int i=0; i<n; i++)
        {
            if (!vis[i])
            {
                dfs(i, adj, vis);
                count++;
            }
        }

        return count;
    }
};
