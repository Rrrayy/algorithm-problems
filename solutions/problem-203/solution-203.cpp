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

 //运用虚拟头结点统一列表删除逻辑，不用分类讨论头结点的值是否等于目标值
 
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==nullptr)
            return head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode *p1,*p2;
        //快慢指针进行删除操作
        p1=dummy;
        p2=dummy->next;
        while(p2!=nullptr){
            if(p2->val==val){
                p1->next=p2->next;
                p2=p2->next;
            }
            else{
                p1=p1->next;
                p2=p2->next;
            }
        }
        return dummy->next;
    }
};
