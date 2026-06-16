class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        if (s[s.size() - 1] == '1')
        {
            return false;
        }
        
        vector<int> can(s.size(), 0);
        can[0] = 1;
        int n = s.size();

        for (int i=0; i<n; i++)
        {
            if (can[i] == 1 && s[i] == '0')
            {
                for (int j=i+minJump; j<n && j<=i+maxJump; j++)
                {
                    can[j] = 1;
                }
            }
        }

        return can[s.size() - 1];
    }
};