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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        int carry = 0;
        while(l1 || l2 || carry){
            int sum = (l1 == nullptr ? 0 : l1->val) + (l2 == nullptr ? 0 : l2->val) + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        return dummy->next;
    }
};

// 根据输入数组构建链表（按输入顺序，即个位在前）
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
    std::vector<int> v1, v2;
    int x;

    std::cout << "input list1 (end with -1): ";
    while(std::cin >> x && x != -1) {
        v1.push_back(x);
    }

    std::cout << "input list2 (end with -1): ";
    while(std::cin >> x && x != -1) {
        v2.push_back(x);
    }

    ListNode* l1 = buildList(v1);
    ListNode* l2 = buildList(v2);

    Solution so;
    ListNode* res = so.addTwoNumbers(l1, l2);

    std::cout << "result: ";
    while(res){
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}