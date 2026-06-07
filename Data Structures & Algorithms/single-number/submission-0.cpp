class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xore = 0;

        for (int n : nums)
        {
            xore = xore ^ n;
        }

        return xore;
    }
};
