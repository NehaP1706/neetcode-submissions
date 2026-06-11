class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> freq;

        for (char c : s)
        {
            freq[c]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &[c, f]: freq)
        {
            pq.push({f, c});
        }

        string res = "";

        pair<int,char> prev = {0,'#'};

        while(!pq.empty()) {
            auto [f,c] = pq.top();
            pq.pop();

            res += c;
            f--;

            if(prev.first > 0) {
                pq.push(prev);
            }

            prev = {f,c};
        }

        return res.size() == s.size() ? res : "";
    }
};