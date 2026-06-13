class Solution {
public:
    int tribonacci(int n) {
        int prevprevprev = 0;
        int prevprev = 1;
        int prev = 1;
        int curr = prev + prevprev + prevprevprev;

        if (n == 0)
        {
            return prevprevprev;
        }

        if (n == 1)
        {
            return prevprev;
        }

        if (n == 2)
        {
            return prev;
        }

        if (n == 3)
        {
            return curr;
        }

        for (int i=4; i<=n; i++)
        {
            prevprevprev = prevprev;
            prevprev = prev;
            prev = curr;
            curr = prevprevprev + prevprev + prev;
        }

        return curr;
    }
};