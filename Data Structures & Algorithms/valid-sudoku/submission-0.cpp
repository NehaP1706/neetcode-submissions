class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // row check ughhhh

        for (int i=0; i<9; i++)
        {
            vector<int> mp(9, 0);
            for (int j=0; j<9; j++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                
                if (board[i][j] < '1' || board[i][j] > '9' || mp[board[i][j] - '1'])
                {
                    //cout << i << j << endl;
                    return false;
                }

                mp[board[i][j] - '1']++;
            }
        }

        // col check ewwww
        for (int j=0; j<9; j++)
        {
            vector<int> mp(9, 0);
            for (int i=0; i<9; i++)
            {
                if (board[i][j] == '.')
                {
                    continue;
                }
                
                if (board[i][j] < '1' || board[i][j] > '9' || mp[board[i][j] - '1'])
                {
                    //cout << i << j << endl;
                    return false;
                }

                mp[board[i][j] - '1']++;
            }
        }

        // 3x3 sighhhhh

        for (int m = 0; m < 3; m++)
        {
            for (int n = 0; n < 3; n++)
            {
                vector<int> mp(9, 0);
                for (int i = m*3; i <= m*3 + 2; i++)
                {
                    for (int j = n*3; j <= n*3 + 2; j++)
                    {   
                        if (board[i][j] == '.')
                        {
                            continue;
                        }
                        
                        //cout << i << " " << j << " " << m << " " << n << " " << mp[board[i][j] - '1'] << endl;

                        if (board[i][j] < '1' || board[i][j] > '9' || mp[board[i][j] - '1'])
                        {
                            //cout << i << j << endl;
                            return false;
                        }

                        mp[board[i][j] - '1']++;

                        //cout << i << " " << j << " " << m << " " << n << " " << mp[board[i][j] - '1'] << endl;

                    }
                }
            }
        }

        return true;
    }
};
