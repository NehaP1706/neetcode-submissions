/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> ps;

        for (int i=0; i<n; i++)
        {
            ps.push_back({intervals[i].start, 1});
            ps.push_back({intervals[i].end, -1});
        }

        sort(ps.begin(), ps.end());
        int count = 0;
        int ans = 0;

        for (int i=0; i<2*n; i++)
        {
            count += ps[i].second;

            ans = max(ans, count);
        }

        return ans;
    }
};
