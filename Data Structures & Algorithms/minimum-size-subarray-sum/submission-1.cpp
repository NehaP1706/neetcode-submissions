class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int cursum = 0;
        int left = 0;
        int mini = INT_MAX;
        
        for (int right = 0; right < nums.size(); right++)
        {
            cursum += nums[right];

            while(cursum >= target)
            {
                cursum -= nums[left];
                mini = min(mini, right - left + 1);
                left++;
            }
        }

        return mini == INT_MAX ? 0 : mini;
    }
};