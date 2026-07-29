#include<iostream>
#include<queue>
#include<vector>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
};

int main(){
    std::vector<int>nums;
    int x;
    while(std::cin>>x)   nums.push_back(x);
    if(nums.empty()||nums[0]==-1)   return 0;
    TreeNode* root =  new TreeNode(nums[0]);
    std::queue<TreeNode*>q;
    q.push(root);
    for(size_t i=1;i<nums.size();){
        TreeNode* node=q.front();
        q.pop();
        if(nums[i]!=-1){
            node->left = new TreeNode(nums[i]);
            q.push(node->left);
        }
        i++;
        if(i>=nums.size())  break;
        if(nums[i]!=-1){
            node->right = new TreeNode(nums[i]);
            q.push(node->right);
        }
        i++;
    }

    while(!q.empty())   q.pop();
    q.push(root);
    while(!q.empty()){
        TreeNode* node = q.front();
        q.pop();
        std::cout<<node->val<<std::endl;
        if(node->left)  q.push(node->left);
        if(node->right) q.push(node->right);
    }
    return 0;
}
