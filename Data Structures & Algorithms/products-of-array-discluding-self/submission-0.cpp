class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffix(n+1, 1);
        vector<int> prefix(n+1, 1);

        for (int i=1; i<=n; i++)
        {
            prefix[i] = prefix[i-1] * nums[i-1];
        }

        for (int i=0; i<=n; i++)
        {
            cout << prefix[i] << " ";
        }

        cout << endl;

        for (int i=n-2; i>=0; i--)
        {
            suffix[i] = suffix[i+1] * nums[i+1];
        }

        for (int i=0; i<=n; i++)
        {
            cout << suffix[i] << " ";
        }

        vector<int> ans;

        for (int i=0; i<n; i++)
        {
            ans.push_back(prefix[i] * suffix[i]);
        }

        return ans;
    }
};
