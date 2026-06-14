class Node {
public:
    Node* links[26];
    int cntEndWith = 0;
    int cntPrefix = 0;

    bool containsKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    Node* get(char ch) {
        return links[ch - 'a'];
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    void increaseEnd() {
        cntEndWith++;
    }

    void increasePrefix() {
        cntPrefix++;
    }

    void deleteEnd() {
        cntEndWith--;
    }

    void reducePrefix() {
        cntPrefix--;
    }

    int getEnd() {
        return cntEndWith;
    }

    int getPrefix() {
        return cntPrefix;
    }

    Node() {
        for(int i = 0; i < 26; i++)
            links[i] = NULL;
    }
};

class WordDictionary {
private:
    Node* root;

public:
    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {
        Node* node = root;

        for(char ch : word) {
            if(!node->containsKey(ch))
                node->put(ch, new Node());

            node = node->get(ch);
            node->increasePrefix();
        }

        node->increaseEnd();
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int idx, Node* node)
    {
        if(node == nullptr)
            return false;

        if(idx == word.size())
            return node->getEnd() > 0;

        char ch = word[idx];

        if(ch != '.')
        {
            if(!node->containsKey(ch))
                return false;

            return dfs(word, idx + 1, node->get(ch));
        }

        for(int i = 0; i < 26; i++)
        {
            if(node->links[i] &&
            dfs(word, idx + 1, node->links[i]))
                return true;
        }

        return false;
    }
};
