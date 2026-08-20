struct node{
    int key;
    int value;
    node* prev;
    node* next;
    node(int k=0 ,int v=0):key(k),value(v){}
};

class LRUCache {
private:
    int capacity;
    node* dummy;
    unordered_map<int,node*> mp;

    void remove(node* x){
        x->prev->next=x->next;
        x->next->prev= x->prev;
    }

    void push_front(node* x){
        x->prev=dummy;
        x->next=dummy->next;
        x->prev->next=x;
        x->next->prev=x;
    }

    node* get_node(int key){
        auto it = mp.find(key);
        if(it==mp.end())
            return nullptr;
        node* node = it->second;
        remove(node);
        push_front(node);
        return node;
    }  
public:

    LRUCache(int capacity):capacity(capacity),dummy(new node()) {
        dummy->prev=dummy;
        dummy->next=dummy;
    }
    
    int get(int key) {
        node* node = get_node(key);
        return node ? node->value :-1;
    }
    
    void put(int key, int value) {
        node* nd= get_node(key);
        if(nd){
            nd->value =value;
            return ;
        }
        nd = new node(key ,value);
        mp[key]=nd;
        push_front(nd);
        if(mp.size()>capacity){
            node* tmp=dummy->prev;
            mp.erase(tmp->key);
            remove(tmp);
            delete(tmp);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
