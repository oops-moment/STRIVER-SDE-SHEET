#include <unordered_map>

class LRUCache {
public:
    class node {
    public:
        int val;
        int key;
        node* next;
        node* prev;
        
        node(int _key, int _val) {
            key = _key;
            val = _val;
            next = nullptr;
            prev = nullptr;
        }
    };

    node* head;
    node* tail;
    int cap;
    std::unordered_map<int, node*> mp;

    LRUCache(int capacity) {
        cap = capacity;
        head = new node(-1, -1);
        tail = new node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (mp.find(key_) != mp.end()) {
            node* resnode = mp[key_];
            int res = resnode->val;
            mp.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            mp[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (mp.find(key_) != mp.end()) {
            node* existingnode = mp[key_];
            mp.erase(key_);
            deletenode(existingnode);
            delete existingnode;
        }

        if (mp.size() == cap) {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(key_, value));
        mp[key_] = head->next;
    }
};
