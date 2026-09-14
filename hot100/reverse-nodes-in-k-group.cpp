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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode* p = head;
        while(p){ len++; p = p->next; }

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* groupprev = dummy;

        while(len >= k){
            ListNode* groupstart = groupprev->next;
            ListNode* groupend = groupstart;
            for(int i = 0; i < k - 1; ++i)
                groupend = groupend->next;
            ListNode* nextgroup = groupend->next;

            ListNode* pre = nullptr;
            ListNode* cur = groupstart;
            for(int i = 0; i < k; ++i){
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }

            groupprev->next = pre;
            groupstart->next = nextgroup;
            groupprev = groupstart;
            len -= k;
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

    std::cout << "input k" << std::endl;
    int k;
    std::cin >> k;

    ListNode* head = buildList(nums);

    Solution so;
    ListNode* res = so.reverseKGroup(head, k);

    std::cout << "result: ";
    while(res){
        std::cout << res->val << " ";
        res = res->next;
    }
    std::cout << std::endl;

    return 0;
}
