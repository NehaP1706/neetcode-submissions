class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";

        priority_queue<pair<int, char>> pq;

        pair<int, char> prev = {0, '#'};

        if (a != 0) pq.push({a, 'a'});
        if (b != 0) pq.push({b, 'b'});
        if (c != 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            auto [cnt1, ch1] = pq.top();
            pq.pop();

            int n = res.size();

            if (n >= 2 && res[n-1] == ch1 && res[n-2] == ch1) {
                if (pq.empty()) break;

                auto [cnt2, ch2] = pq.top();
                pq.pop();

                res += ch2;
                cnt2--;

                if (cnt2 > 0)
                    pq.push({cnt2, ch2});

                pq.push({cnt1, ch1});
            }
            else {
                res += ch1;
                cnt1--;

                if (cnt1 > 0)
                    pq.push({cnt1, ch1});
            }
        }

        return res;
    }
};