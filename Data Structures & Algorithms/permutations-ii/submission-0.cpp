class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>> perm = permute(nums);

        vector<vector<int>> ans;

        for (auto temp: perm)
        {
            ans.push_back(temp);
        }

        return ans;
    }
    void solve(vector<int>& nums,
               set<vector<int>>& res,
               vector<int>& partial,
               vector<bool>& used)
    {
        if (partial.size() == nums.size()) {
            res.insert(partial);
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

    set<vector<int>> permute(vector<int>& nums) {
        set<vector<int>> res;
        vector<int> partial;
        vector<bool> used(nums.size(), false);

        solve(nums, res, partial, used);

        return res;
    }
};