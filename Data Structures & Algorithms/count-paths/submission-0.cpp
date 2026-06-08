class Solution {
public:
    int uniquePaths(int m, int n) {
        long long ans = 1;

        int k = min(m - 1, n - 1);

        for (int i = 1; i <= k; i++) {
            ans = ans * (m + n - 2 - k + i) / i;
        }

        return (int)ans;
    }
};
