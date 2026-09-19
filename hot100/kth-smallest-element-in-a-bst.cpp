/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // void dfs(TreeNode*node,vector<int>& nums){
    //     if(node==nullptr)   return;
    //     dfs(node->left,nums);
    //     nums.push_back(node->val);
    //     dfs(node->right,nums);
    // }
    // int kthSmallest(TreeNode* root, int k) {
    //     vector<int> nums;
    //     dfs(root,nums);
    //     return nums[k-1];

        int kthSmallest(TreeNode* root, int k){
            stack<TreeNode*>st;
            TreeNode*cur=root;
            while(cur||!st.empty()){
                while(cur){
                    st.push(cur);
                    cur=cur->left;
                }
                cur=st.top();
                st.pop();
                if(--k==0)  return cur->val;
                cur=cur->right;
            }
            return -1;
        } 
};
