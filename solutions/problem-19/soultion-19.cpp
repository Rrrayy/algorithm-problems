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
//思路是先求出链表总长度，再用总长度减去n，求出正序要删除链表元素的下标，进而从链表头顺序找到删除元素进行删除操作即可
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count=0;
        ListNode* p=head;
        while(p!=nullptr){
            count++;
            p=p->next;
        }
        int index=count-n;
        ListNode*  dummy=new ListNode();
        dummy->next=head;
        ListNode* q=dummy;
        ListNode* r=head;
        while(index!=0){
            q=q->next;
            r=r->next;
            index--;
        }
        q->next=r->next;
        r->next=nullptr;
        return dummy->next;
    }
};
