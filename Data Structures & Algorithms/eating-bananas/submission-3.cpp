class Solution {
public:
    bool check(int k, vector<int>& piles, int h)
    {
        int ans = 0;
        int n = piles.size();

        for (int i=0; i<n; i++)
        {
            ans += (piles[i] / k);

            if (piles[i]%k)
            {
                ans++;
            }
        }

        cout << k << " " << ans << endl;
        return ans <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();

        int mini = INT_MAX;
        int maxi = INT_MIN;

        for (int i=0; i<n; i++)
        {
            mini = min(mini, piles[i]);
            maxi = max(maxi, piles[i]);
        }

        int res = maxi;

        //if (n == 1)
        //{
            mini = 1;
        //}

        while (mini <= maxi)
        {
            int mid = mini + (maxi - mini)/2;

            if (check(mid, piles, h))
            {
                res = min(res, mid);
                maxi = mid - 1;
            }
            else
            {
                mini = mid + 1;
            }
        }

        return res;
    }
};
