class MyLinkedList {
private:
struct ListNode{
    int val_;
    ListNode* next;
    ListNode(int val):val_(val),next(nullptr){}
};
    int capacity;     //链表容量  
    ListNode *dummy;  //虚拟头结点
public:
    MyLinkedList() {
        dummy = new ListNode(0);
        capacity=0;
    }
    
    int get(int index) {
        if(index>capacity-1)
            return -1;
        ListNode *p1=dummy->next;
        while(index--){
            p1=p1->next;
        }
        return p1->val_;
    }
    
    void addAtHead(int val) {
        ListNode* node=new ListNode(val);
        node->next=dummy->next;
        dummy->next=node;
        capacity++;
    }
    
    void addAtTail(int val) {
        ListNode* node = new ListNode(val);
        ListNode* p2=dummy;
        while(p2->next!=nullptr){
            p2=p2->next;
        }
        p2->next=node;
        capacity++;
    }
    
    void addAtIndex(int index, int val) {
        ListNode* node=new ListNode(val);
        if(index>capacity)
            return;
        ListNode *p3=dummy;
        while(index--){
            p3=p3->next;
        }
        node->next=p3->next;
        p3->next=node;
        capacity++;
    }
    
    void deleteAtIndex(int index) {
        if(index>=capacity)
            return;
        ListNode* p4=dummy;
        while(index--){
            p4=p4->next;
        }
        ListNode* tmp=p4->next;
        p4->next=p4->next->next;
        delete(tmp);
        capacity--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
