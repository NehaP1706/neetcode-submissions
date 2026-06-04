class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, vector<int>>> pq;

        int n = points.size();

        vector<vector<int>> res;

        for (int i=0; i<n; i++)
        {
            pq.push({(points[i][0]*points[i][0] + points[i][1]*points[i][1]), points[i]});

            if (pq.size() > k)
            {
                pq.pop();
            }
        }

        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
};
