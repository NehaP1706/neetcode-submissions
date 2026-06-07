class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        vector<int> ans;

        int n = digits.size();
        int carry = 1;

        for (int i=0; i<n; i++)
        {
            ans.push_back((digits[i] + carry)%10);
            carry = (digits[i] + carry)/10;
        }

        if (carry)
        {
            ans.push_back(carry);
        }

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
