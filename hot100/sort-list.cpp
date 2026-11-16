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
    ListNode* sortList(ListNode* head) {
        vector<int> nums;
        ListNode* cur=head;
        while(cur){
            nums.push_back(cur->val);
            cur=cur->next;
        }
        sort(nums.begin(),nums.end());
        ListNode* dummy= new ListNode(0);
        ListNode* cur1=dummy;
        for(int i=0;i<nums.size();++i){
            cur1->next=new ListNode(nums[i]);
            cur1=cur1->next;
        }
        return dummy->next;
    }
};