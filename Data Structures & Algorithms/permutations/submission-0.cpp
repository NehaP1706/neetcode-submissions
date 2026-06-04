class Solution {
public:
    void solve(vector<int>& nums,
               vector<vector<int>>& res,
               vector<int>& partial,
               vector<bool>& used)
    {
        if (partial.size() == nums.size()) {
            res.push_back(partial);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            if (used[i])
                continue;

            used[i] = true;
            partial.push_back(nums[i]);

            solve(nums, res, partial, used);

            partial.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> partial;
        vector<bool> used(nums.size(), false);

        solve(nums, res, partial, used);

        return res;
    }
};