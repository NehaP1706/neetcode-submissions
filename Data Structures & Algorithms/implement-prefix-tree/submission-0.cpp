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

class PrefixTree {
private:
    Node* root;

public:
    PrefixTree() {
        root = new Node();
    }

    void insert(string word) {
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
        Node* node = root;

        for(char ch : word) {
            if(!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return node->getEnd() > 0;
    }

    bool startsWith(string prefix) {
        Node* node = root;

        for(char ch : prefix) {
            if(!node->containsKey(ch))
                return false;

            node = node->get(ch);
        }

        return true;
    }
};

