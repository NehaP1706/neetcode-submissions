class Solution {
public:
    bool check(int num, vector<int>& weights, int days)
    {
        int ships = 1, currCap = num;
        for (int w : weights) {
            if (currCap - w < 0) {
                ships++;
                if (ships > days) {
                    return false;
                }
                currCap = num;
            }
            currCap -= w;
        }
        return true;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = INT_MIN;
        int high = 0;

        for (int i=0; i<n; i++)
        {
            low = max(low, weights[i]);
            high += weights[i];
        }

        int res = high;

        while(low <= high)
        {
            int mid = low + (high - low)/2;

            if (check(mid, weights, days))
            {
                res = min(res, mid);
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        return res;
    }
};