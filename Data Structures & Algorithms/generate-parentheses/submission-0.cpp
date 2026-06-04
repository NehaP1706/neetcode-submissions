class Solution {
public:
    void solve(int n, int open, int close, string& cur, vector<string>& res)
    {
        if (cur.size() == 2 * n) {
            res.push_back(cur);
            return;
        }

        if (open < n) {
            cur.push_back('(');
            solve(n, open + 1, close, cur, res);
            cur.pop_back();
        }

        if (close < open) {
            cur.push_back(')');
            solve(n, open, close + 1, cur, res);
            cur.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string cur;

        solve(n, 0, 0, cur, res);

        return res;
    }
};
