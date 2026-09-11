#include<iostream>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* pre = nullptr;
        while(cur){
            ListNode* temp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = temp;
        }
        return pre;
    }

    bool isPalindrome(ListNode* head) {
        if(!head||!head->next)  return true;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next&&fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* index=reverseList(slow->next);
        ListNode* p1=head;
        ListNode* p2=index;
        while(p2){
            if(p1->val!=p2->val)    return false;
            p1=p1->next;
            p2=p2->next;
        }
        return true;
    }
};