class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans = 0;

        while(n)
        {
            ans += (n & 1);
            n = n >> 1;
        }

        return ans;
    }

    vector<int> countBits(int n) {
        vector<int> res;

        for (int i=0; i<=n; i++)
        {
            res.push_back(hammingWeight(i));
        }

        return res;
    }
};
