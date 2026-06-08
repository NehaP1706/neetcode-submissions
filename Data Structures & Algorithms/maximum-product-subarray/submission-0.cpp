class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curMax = nums[0];
        int curMin = nums[0];
        int ans = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int x = nums[i];

            int a = x;
            int b = x * curMax;
            int c = x * curMin;

            curMax = max({a, b, c});
            curMin = min({a, b, c});

            ans = max(ans, curMax);
        }

        return ans;
    }
};