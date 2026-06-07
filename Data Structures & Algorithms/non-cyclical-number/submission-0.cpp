class Solution {
public:
    bool isHappy(int n) {
        set<int> st;
        int prev = 0;

        while(n != 1)
        {
            int num = n;
            int sum = 0;

            while(num)
            {
                int digi = num%10;
                sum += (digi * digi);
                num = num/10;
            }

            n = sum;
            st.insert(sum);

            if (st.size() == prev && sum != 1)
            {
                return false;
            }

            prev = st.size();
        }

        return true;
    }
};
