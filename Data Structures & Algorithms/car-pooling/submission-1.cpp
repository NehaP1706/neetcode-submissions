class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int, int>> t;

        int n = trips.size();
        for (int i=0; i<n; i++)
        {
            t.push_back({trips[i][1], trips[i][0]});
            t.push_back({trips[i][2], trips[i][0] * -1});
        }

        sort(t.begin(), t.end());

        int start = 0;

        for (int i=0; i<2*n; i++)
        {
            start += t[i].second;

            if (start < 0 || start > capacity)
            {
                return false;
            }
        }

        return true;
    }
};