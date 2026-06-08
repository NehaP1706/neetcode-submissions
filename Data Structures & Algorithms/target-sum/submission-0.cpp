class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total = accumulate(nums.begin(), nums.end(), 0);

        // P = (target + total) / 2 must be an integer >= 0
        if (abs(target) > total) return 0;
        if ((target + total) % 2) return 0;

        int req = (target + total) / 2;

        vector<int> dp(req + 1, 0);
        dp[0] = 1;

        for (int x : nums) {
            for (int s = req; s >= x; s--) {
                dp[s] += dp[s - x];
            }
        }

        return dp[req];
    }
};