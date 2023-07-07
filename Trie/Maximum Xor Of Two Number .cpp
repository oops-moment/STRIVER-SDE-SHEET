struct Node {
    Node* links[2];
    bool flag;

    Node() {
        for (int i = 0; i < 2; i++) {
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

    void insert_for_max_xor(const string& word, string& ans) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links['1'- ch]) {
                ans += "0";
                 node = node->links[ch - '0'];
            }
            else {
                ans += "1";
                node = node->links['1'- ch];

            }
        }
    }

    void insert(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links[ch - '0']) {
                node->links[ch - '0'] = new Node();
            }
            node = node->links[ch - '0'];
        }
        node->flag = true;
    }

    bool search(const string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links[ch - '0']) {
                return false;
            }
            node = node->links[ch - '0'];
        }
        return node->flag;
    }

    bool startsWith(const string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->links[ch - '0']) {
                return false;
            }
            node = node->links[ch - '0'];
        }
        return true;
    }
};

class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        Trie trie;
        map<int, string> mp;

        for (int num : nums) {
            string binary = convertToBinary(num);
            mp[num] = binary;
            trie.insert(binary);
        }

        int maxXOR = 0;
        for (int num : nums) {
            string answer;
            trie.insert_for_max_xor(mp[num], answer);
            int xorValue = convertToDecimal(answer);
            maxXOR = max(maxXOR, xorValue);
        }

        return maxXOR;
    }

private:
    string convertToBinary(int num) {
        string binary;
        for (int i = 31; i >= 0; i--) {
            if (num & (1 << i)) {
                binary += '1';
            }
            else {
                binary += '0';
            }
        }
        return binary;
    }

    int convertToDecimal(const string& binary) {
        int decimal = 0;
        for (char ch : binary) {
            decimal = (decimal << 1) + (ch - '0');
        }
        return decimal;
    }
};
