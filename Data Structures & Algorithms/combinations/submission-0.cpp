class Solution {
public:
    void solve(vector<int>& nums, int k, vector<vector<int>>& res, int idx, int n, vector<int>& partial)
    {
        if (partial.size() == k)
        {
            res.push_back(partial);
            return;
        }

        for (int i = idx; i < n; i++)
        {
            partial.push_back(nums[i]);
            solve(nums, k, res, i+1, n, partial);
            partial.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> nums;

        for (int i=1; i<=n; i++)
        {
            nums.push_back(i);
        }

        vector<vector<int>> res;
        vector<int> partial;

        solve(nums, k, res, 0, n, partial);

        return res;
    }
};