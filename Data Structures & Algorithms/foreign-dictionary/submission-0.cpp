class Solution {
public:
    string foreignDictionary(vector<string>& words) {

        unordered_map<char, unordered_set<char>> adj;
        unordered_map<char, int> indegree;

        for(auto &word : words)
        {
            for(char c : word)
                indegree[c] = 0;
        }

        int n = words.size();

        for(int i = 0; i < n - 1; i++)
        {
            string &a = words[i];
            string &b = words[i + 1];

            int len = min(a.size(), b.size());

            bool found = false;

            for(int j = 0; j < len; j++)
            {
                if(a[j] != b[j])
                {
                    if(adj[a[j]].insert(b[j]).second)
                        indegree[b[j]]++;

                    found = true;
                    break;
                }
            }

            if(!found && a.size() > b.size())
                return "";
        }

        queue<char> q;

        for(auto &[c, deg] : indegree)
        {
            if(deg == 0)
                q.push(c);
        }

        string ans;

        while(!q.empty())
        {
            char node = q.front();
            q.pop();

            ans += node;

            for(char nbr : adj[node])
            {
                indegree[nbr]--;

                if(indegree[nbr] == 0)
                    q.push(nbr);
            }
        }

        return ans.size() == indegree.size() ? ans : "";
    }
};