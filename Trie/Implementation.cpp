struct Node {
    Node* links[26];
    bool flag;

    Node() {
        for (int i = 0; i < 26; i++) {
            links[i] = nullptr;
        }
        flag = false;
    }
};

class Trie {
private:
    Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->links[ch - 'a']) {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }

    bool search(string word) {
        Node* node = root;
        for (int i = 0; i < word.length(); i++) {
            char ch = word[i];
            if (!node->links[ch - 'a']) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        return node->flag;
    }

    bool startsWith(string prefix) {
        Node* node = root;
        for (int i = 0; i < prefix.length(); i++) {
            char ch = prefix[i];
            if (!node->links[ch - 'a']) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        return true;
    }
};
