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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummy=new ListNode(0);
        ListNode *cur=dummy;
        //设置进位变量 如果当前l1和l2两数之和大于10，通过进位则可以在指针后移的同时是后一和加上前俩数进位结果，符合题意
        int count=0;
        while(l1||l2||count){
            int sum=(l1?l1->val:0)+(l2?l2->val:0)+count;
            count=sum/10;
            cur->next=new ListNode(sum%10);
            cur=cur->next;
            if(l1)  l1=l1->next;
            if(l2)  l2=l2->next;
        }
        return dummy->next;
    }
};
