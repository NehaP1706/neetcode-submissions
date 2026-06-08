class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();

        // suffix i ... n -1 can be segmented?
        vector<int> dp(n+1, 0);
        dp[n] = 1; 

        for (int i = n - 1; i >= 0; i--) 
        {
            for (string& word : wordDict) 
            {
                int len = word.size();

                if (i + len <= n && s.substr(i, len) == word && dp[i + len]) {

                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};
