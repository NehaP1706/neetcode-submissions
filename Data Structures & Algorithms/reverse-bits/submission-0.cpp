class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        int count = 32;

        while(count--)
        {
            ans = (ans << 1) + (n & 1);
            n = (n >> 1);

            //cout << ans;
        }

        return ans;
    }
};
