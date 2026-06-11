class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int total = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (total % 4)
        {
            return false;
        }

        int side = total / 4;

        vector<int> sides(4, 0);
        sort(matchsticks.rbegin(), matchsticks.rend());

        return dfs(matchsticks, sides, 0, side);
    }

private:
    bool dfs(vector<int>& matchsticks, vector<int>& sides, int index, int length) {
        if (index == matchsticks.size()) {
            return true;
        }

        for (int i = 0; i < 4; i++) {
            if (sides[i] + matchsticks[index] <= length) {
                sides[i] += matchsticks[index];
                if (dfs(matchsticks, sides, index + 1, length)) return true;
                sides[i] -= matchsticks[index];
            }

            if (sides[i] == 0) break;
        }

        return false;
    }
};

