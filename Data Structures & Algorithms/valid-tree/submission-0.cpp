class Solution {
public:
    bool isCycle(int node, int parent, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for (int nei : adj[node])
        {
            if (!vis[nei])
            {
                if (isCycle(nei, node, adj, vis))
                    return true;
            }
            else if (nei != parent)
            {
                return true;
            }
        }

        return false;
    }

    bool validTree(int n, vector<vector<int>>& edges) {

        if (edges.size() != n - 1)
            return false;

        vector<vector<int>> adj(n);

        for (auto &e : edges)
        {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(n, 0);

        if (isCycle(0, -1, adj, vis))
            return false;

        for (int i = 0; i < n; i++)
        {
            if (!vis[i])
                return false;
        }

        return true;
    }
};