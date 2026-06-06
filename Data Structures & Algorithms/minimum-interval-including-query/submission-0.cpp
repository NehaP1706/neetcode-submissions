class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        int n = intervals.size();
        int m = queries.size();
        vector<int> ans;

        for (int i=0; i<m; i++)
        {
            int a = INT_MAX;

            for (int j=0; j<n; j++)
            {
                if (queries[i] >= intervals[j][0] && queries[i] <= intervals[j][1])
                {
                    a = min(a, intervals[j][1] - intervals[j][0] + 1);
                }
            }

            if (a == INT_MAX)
            {
                a = -1;
            }

            ans.push_back(a);
        }
        
        return ans;
    }
};
