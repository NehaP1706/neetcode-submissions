class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        vector<vector<int>> dp(n, vector<int>(n, 0));

        int start = 0;
        int maxLen = 1;

        // length 1
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;

        // length 2
        for (int i = 0; i < n - 1; i++)
        {
            if (s[i] == s[i+1])
            {
                dp[i][i+1] = 1;
                start = i;
                maxLen = 2;
            }
        }

        // length >= 3
        for (int len = 3; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;

                if (s[i] == s[j] && dp[i+1][j-1])
                {
                    dp[i][j] = 1;

                    if (len > maxLen)
                    {
                        maxLen = len;
                        start = i;
                    }
                }
            }
        }

        return s.substr(start, maxLen);
    }
};
