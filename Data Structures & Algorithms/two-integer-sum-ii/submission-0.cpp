class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();

        int high = n - 1;
        int low = 0;

        int start = numbers[low] + numbers[high];

        while(start != target)
        {
            if (start > target)
            {
                high--;
            }
            else
            {
                low++;
            }

            start = numbers[low] + numbers[high];
        }

        vector<int> ans;

        //for (int i = 0; i<2; i++)
        //{
            ans.push_back(low + 1);
            ans.push_back(high + 1);
        //}

        return ans;
    }
};
