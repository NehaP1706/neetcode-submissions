class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj (n);

        int m = flights.size();

        for (int i=0; i<m; i++)
        {
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];

            adj[u].push_back({v, w});
        }

        int stops = 0;

        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        // price (w), stops, node
        pq.push({0, 0, src});
        //vector<int> vis(n, 0);

        while(!pq.empty())
        {
            auto node = pq.top();
            pq.pop();
            //vis[node[2]] = 1;

            //cout << node[0] << " " << node[1] << " " << node[2] << endl;

            if (node[2] == dst && node[1] <= k + 1)
            {
                return node[0];
            }

            for (auto &v : adj[node[2]])
            {
                //if (!vis[v.first])
                //{
                    pq.push({node[0]+v.second,node[1]+1, v.first});
                //}
            }
        }

        return -1;
    }
};
