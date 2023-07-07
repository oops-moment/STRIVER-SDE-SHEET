we need to tell a string that has all its prefix in the array
#include <bits/stdc++.h>

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

    void insert(const std::string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a']) {
                node->links[ch - 'a'] = new Node();
            }
            node = node->links[ch - 'a'];
        }
        node->flag = true;
    }

    bool search(const std::string& word) {
        Node* node = root;
        for (char ch : word) {
            if (!node->links[ch - 'a']) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        return node->flag;
    }

    bool startsWith(const std::string& prefix) {
        Node* node = root;
        for (char ch : prefix) {
            if (!node->links[ch - 'a']) {
                return false;
            }
            node = node->links[ch - 'a'];
        }
        return true;
    }
};

bool compareStrings(const std::string& s1, const std::string& s2) {
    if (s1.length() < s2.length()) {
        return true;
    }
    else if (s1.length() > s2.length()) {
        return false;
    }
    else {
        return s1 > s2;
    }
}
std::string completeString(int n, std::vector<std::string>& a) {
    Trie temp;

    for (int j = 0; j < a.size(); j++) {
        temp.insert(a[j]);
    }
    
    std::sort(a.begin(), a.end(), compareStrings);
   
    for (int i = a.size()-1; i >=0; i--) {
        int flag = 0;
        for (int k = 1; k <= a[i].length(); k++) {
            std::string prefix = a[i].substr(0, k);
            if (!temp.search(prefix)) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            return a[i];
        }
    }

    return "None";
}
