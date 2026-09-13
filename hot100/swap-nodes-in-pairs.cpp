#include<iostream>
#include<vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* cur = dummy;
        while(cur->next && cur->next->next){
            ListNode* p = cur->next;
            ListNode* q = p->next;
            p->next = q->next;
            q->next = p;
            cur->next = q;
            cur = p;
        }
        return dummy->next;
    }
};

// 根据数组构建链表
ListNode* buildList(const std::vector<int>& nums) {
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    for(int x : nums) {
        cur->next = new ListNode(x);
        cur = cur->next;
    }
    return dummy->next;
}

int main(){
    int n;
    std::cout << "input list's size" << std::endl;
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "input list's elements" << std::endl;
    for(int i = 0; i < n; ++i)
        std::cin >> nums[i];

    ListNode* head = buildList(nums);

    Solution so;
    ListNode* res = so.swapPairs(head);

    std::cout << "result: ";
    while(res){
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}