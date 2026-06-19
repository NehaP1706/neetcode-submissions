class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
       while(columnNumber)
       {
            columnNumber--;
            int rem = columnNumber % 26;
            //cout << rem << endl;

            res += (rem + 'A');
            columnNumber /= 26;
       } 

       reverse(res.begin(), res.end());
       return res;
    }
};