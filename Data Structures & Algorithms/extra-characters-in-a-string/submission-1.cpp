class Solution {
public:

    class Node {
    public:
        Node* links[26];
        int cntEndWith = 0;

        Node() {
            for(int i=0;i<26;i++)
                links[i] = nullptr;
        }

        bool containsKey(char ch) {
            return links[ch-'a'] != nullptr;
        }

        Node* get(char ch) {
            return links[ch-'a'];
        }

        void put(char ch, Node* node) {
            links[ch-'a'] = node;
        }

        void increaseEnd() {
            cntEndWith++;
        }

        int getEnd() {
            return cntEndWith;
        }
    };

    Node* root;

    void insert(string& word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->containsKey(ch))
                node->put(ch,new Node());

            node = node->get(ch);
        }

        node->increaseEnd();
    }

    vector<int> memo;

    int dfs(int i, string& s) {
        int n = s.size();

        if(i == n)
            return 0;

        if(memo[i] != -1)
            return memo[i];

        // option 1: s[i] is extra
        int ans = 1 + dfs(i+1,s);

        Node* node = root;

        // option 2: match dictionary words
        for(int j=i;j<n;j++) {

            if(!node->containsKey(s[j]))
                break;

            node = node->get(s[j]);

            if(node->getEnd() > 0) {
                ans = min(ans, dfs(j+1,s));
            }
        }

        return memo[i] = ans;
    }

    int minExtraChar(string s, vector<string>& dictionary) {

        root = new Node();

        for(auto& word : dictionary)
            insert(word);

        memo.assign(s.size(),-1);

        return dfs(0,s);
    }
};