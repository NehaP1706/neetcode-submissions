class Solution {
public:
    void solve(vector<int>& nums, vector<vector<int>>& res, int ind, vector<int>& partial)
    {
        res.push_back(partial);

        for (int i = ind; i < nums.size(); i++) {

            if (i > ind && nums[i] == nums[i - 1])
                continue;

            partial.push_back(nums[i]);

            solve(nums, res, i + 1, partial);

            partial.pop_back();
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> partial;

        solve(nums, res, 0, partial);

        return res;
    }
};
