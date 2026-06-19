class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {

        int n = stoneValue.size();

        vector<int> dp(n + 1, 0);

        for (int i = n - 1; i >= 0; i--)
        {
            dp[i] = INT_MIN;

            int curr = 0;

            for (int take = 1; take <= 3 && i + take - 1 < n; take++)
            {
                curr += stoneValue[i + take - 1];
                dp[i] = max(dp[i], curr - dp[i + take]);
            }
        }

        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";

        return "Tie";
    }
};