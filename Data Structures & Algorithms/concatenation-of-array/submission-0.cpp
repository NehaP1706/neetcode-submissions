class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> numss;

        for (int i=0; i<nums.size(); i++)
        {
            numss.push_back(nums[i]);
        }

        for (int i=0; i<nums.size(); i++)
        {
            numss.push_back(nums[i]);
        }

        return numss;
    }
};