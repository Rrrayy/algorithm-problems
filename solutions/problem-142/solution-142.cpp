/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
//数学问题，设置快慢指针，如果链表中存在环，则快慢指针一定在某一结点相遇
//此时设置指针1从头开始走，指针2从相遇结点开始走，则二者相遇时的结点即是环形链表入口节点
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=nullptr&&fast->next!=nullptr){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                ListNode* index1=head;
                ListNode* index2=fast;
                while(index1!=index2){
                    index1=index1->next;
                    index2=index2->next;
                }
            return index2;
            }
        }
        return nullptr;
    }
};
