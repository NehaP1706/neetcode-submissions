class Solution {
public:
    void solve(vector<int>& nums, int target, int sum,
               vector<vector<int>>& res,
               int ind,
               vector<int>& partial)
    {
        if (sum == target) {
            res.push_back(partial);
            return;
        }

        for (int i = ind; i < nums.size(); i++) {

            if (i > ind && nums[i] == nums[i - 1])
                continue;

            if (sum + nums[i] > target)
                break;

            partial.push_back(nums[i]);

            solve(nums, target, sum + nums[i],
                  res, i + 1, partial);

            partial.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> partial;

        solve(nums, target, 0, res, 0, partial);

        return res;
    }
};