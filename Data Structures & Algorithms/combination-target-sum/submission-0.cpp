class Solution {
public:
    void solve(vector<int>& nums, int target, int sum, vector<vector<int>>& res, int ind, vector<int>& partial)
    {
        if (sum == target)
        {
            res.push_back(partial);
            return;
        }

        int n = nums.size();

        for (int i=ind; i<n; i++)
        {
            if (sum + nums[i] <= target)
            {
                partial.push_back(nums[i]);
                cout << ind << " " << nums[i] << endl;
                solve(nums, target, sum + nums[i], res, i, partial);
                partial.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;

        int sum = 0;
        int i = 0;
        vector<int> partial;

        solve(nums, target, sum, res, i, partial);

        return res;
    }
};
