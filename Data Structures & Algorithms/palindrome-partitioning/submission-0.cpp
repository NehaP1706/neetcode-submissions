class Solution {
public:
    bool isPalindrome(string& s, int l, int r)
    {
        while (l < r)
        {
            if (s[l] != s[r])
                return false;

            l++;
            r--;
        }

        return true;
    }

    void solve(string& s, int ind, vector<string>& partial, vector<vector<string>>& res)
    {
        if (ind == s.size())
        {
            res.push_back(partial);
            return;
        }

        for (int i = ind; i < s.size(); i++)
        {
            if (isPalindrome(s, ind, i))
            {
                partial.push_back(s.substr(ind, i - ind + 1));

                solve(s, i + 1, partial, res);

                partial.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> partial;

        solve(s, 0, partial, res);

        return res;
    }
};