struct node {
        int key;
        int value;
        node* prev;
        node* next;
        node(int k=0, int v=0) : key(k), value(v) {}
    };
class LRUCache {
public:
    int capacity;
    unordered_map<int, node*> mp;
    node* dummy;

    void remove(node* x) {
        x->next->prev = x->prev;
        x->prev->next = x->next;
    }
    void pushfront(node* x) {
        x->prev = dummy;
        x->next = dummy->next;
        x->prev->next = x;
        x->next->prev = x;
    }

    node* getnode(int key) {
        auto it = mp.find(key);
        if (it == mp.end())
            return nullptr;
        remove(mp[key]);
        pushfront(mp[key]);
        return mp[key];
    }

    LRUCache(int capacity) : capacity(capacity), dummy(new node()) {
        dummy->next = dummy;
        dummy->prev = dummy;
    }

    int get(int key) {
        node* node = getnode(key);
        if (node)
            return node->value;
        else
            return -1;
    }

    void put(int key, int value) {
        node* cur = getnode(key);
        if (cur) {
            cur->value = value;
            return;
        }
        cur = new node(key, value);
        mp[key] = cur;
        pushfront(cur);
        if (mp.size() > capacity) {
            node* tmp = dummy->prev;
            mp.erase(tmp->key);
            remove(tmp);
            delete (tmp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */