class Solution {
public:
    bool bfs(int src, int dest, vector<vector<int>>& adj, vector<int>& vis)
    {
        priority_queue<int, vector<int>, greater<int>> pq;

        pq.push(src);

        while(!pq.empty())
        {
            int s = pq.top();
            pq.pop();
            vis[s] = 1;

            if (s == dest)
            {
                return true;
            }

            for (int nei : adj[s])
            {
                if(!vis[nei])
                {
                    pq.push(nei);
                }
            }
        }

        return false;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int>> adj(numCourses);

        for (auto &e: prerequisites)
        {
            adj[e[1]].push_back(e[0]);
        }

        int m = queries.size();
        vector<bool> ans(m, false);

        for (int i=0; i<m; i++)
        {
            vector<int> vis(numCourses, 0);
            ans[i] = bfs(queries[i][1], queries[i][0], adj, vis);
        }

        return ans;
    }
};