#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int x):val(x),next(nullptr) {}
};

ListNode* create(const vector<int>& nums){
    if(nums.empty())
        return nullptr;
    ListNode* head= new ListNode(nums[0]);
    ListNode* cur=head;
    for(size_t i=1;i<nums.size();++i){
        cur->next=new ListNode(nums[i]);
        cur=cur->next;
    }
    return head;
}

void printList(ListNode* head){
    ListNode* cur=head;
    while(cur){
        cout<<cur->val<<endl;
        cur=cur->next;
    }
}

int main(){
    int n;
    cin>>n;
    vector<int >nums(n);
    for(int i=0;i<n;++i)
        cin>>nums[i];
    ListNode* head=create(nums);
    printList(head);
    return 0;
}
