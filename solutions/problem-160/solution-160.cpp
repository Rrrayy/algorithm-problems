/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

 //A的非相交路程+相交路程+b的未相交路程=a+c+b==b+c+a
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a=headA;
        ListNode *b=headB;
        while(a!=b){
            a=(a==NULL)?headB:a->next;
            b=(b==NULL)?headA:b->next;
        }
        return a;
    }
};
