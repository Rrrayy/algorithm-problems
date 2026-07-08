/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode *p ,*q;
        ListNode *dummy=new ListNode(0);
        dummy->next=head;
        ListNode *cur=dummy;
        while(cur->next!=nullptr&&cur->next->next!=nullptr){
            ListNode* p=cur->next;
            ListNode* q=p->next;
            p->next=q->next;
            q->next=p;
            cur->next=q;
            cur=p;
        }
        return dummy ->next;
    }
};
