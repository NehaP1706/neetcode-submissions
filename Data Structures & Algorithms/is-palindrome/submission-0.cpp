class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        string newe = "";

        for (int i=0; i<n; i++)
        {
            if (s[i] == ' ')
            {
                continue;
            }
            
            if (!((s[i] >= 'a' && s[i] <= 'z') ||
                (s[i] >= 'A' && s[i] <= 'Z') ||
                (s[i] >= '0' && s[i] <= '9')))
            {
                continue;
            }
            
            if (s[i] >= 'A' && s[i] <= 'Z')
            {
                newe += (s[i] - 'A' + 'a');
            }
            else
            {
                newe += s[i];
            }
        }

        string rev = newe;
        cout << newe;
        reverse(newe.begin(), newe.end());

        return rev == newe;
    }
};
