class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n0 = 0, n1 = 0, n2 = 0;

        for (int n : nums)
        {
            if (n == 0)
            {
                n0++;
            }
            else if (n == 1)
            {
                n1++;
            }
            else
            {
                n2++;
            }
        }

        int i = 0;

        while(n0--)
        {
            nums[i++] = 0;
        }

        while(n1--)
        {
            nums[i++] = 1;
        }

        while(n2--)
        {
            nums[i++] = 2;
        }
    }
};