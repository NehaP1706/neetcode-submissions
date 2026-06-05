class Solution {
public:
    bool isCycle(int node, vector<vector<int>>& adj, vector<int>& vis)
    {
        vis[node] = 1;

        for (int nei : adj[node])
        {
            if (vis[nei] == 1)
                return true;

            if (vis[nei] == 0)
            {
                if (isCycle(nei, adj, vis))
                    return true;
            }
        }

        vis[node] = 2;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj (numCourses);

        int m = prerequisites.size();
        for (int i=0; i<m; i++)
        {
            int one = prerequisites[i][0];
            int two = prerequisites[i][1];

            adj[two].push_back(one);
        }

        vector<int> vis(numCourses, 0);

        for (int i = 0; i < numCourses; i++)
        {
            if (vis[i] == 0)
            {
                if (isCycle(i, adj, vis))
                    return false;
            }
        }

        return true;
    }
};
