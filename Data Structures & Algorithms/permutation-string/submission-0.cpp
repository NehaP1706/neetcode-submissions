class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> mp(26, 0);

        int n = s1.size();

        for (int i=0; i<n; i++)
        {
            mp[s1[i]-'a']++;
        }

        vector<int> mpp(26, 0);

        int m = s2.size();

        if (m < n)
        {
            return false;
        }

        for (int i=0; i<n; i++)
        {
            mpp[s2[i]-'a']++;
        }

        for (int i=n; i<m; i++)
        {
            if (mpp == mp)
            {
                return true;
            }
            else
            {
                mpp[s2[i-n]-'a']--;
                mpp[s2[i]-'a']++;
            }
        }

        return mpp == mp;
    }
};
