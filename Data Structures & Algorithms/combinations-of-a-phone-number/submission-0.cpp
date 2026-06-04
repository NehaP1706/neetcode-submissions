class Solution {
public:
    unordered_map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    void solve(string& digits, int ind, string& partial, vector<string>& res)
    {
        if (ind == digits.size())
        {
            res.push_back(partial);
            return;
        }

        string letters = mp[digits[ind]];

        for (char c : letters)
        {
            partial.push_back(c);

            solve(digits, ind + 1, partial, res);

            partial.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> res;
        string partial;

        solve(digits, 0, partial, res);

        return res;
    }
};