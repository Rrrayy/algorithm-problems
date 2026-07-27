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
    bool treaversal(TreeNode* node, int count){
        if(node->left==nullptr&&node->right==nullptr&&count==0) return true;
        if(node->left==nullptr&&node->right==nullptr)   return false;
        if(node->left){
            count-=node->left->val;
            if(treaversal(node->left,count))    return true;
            count+=node->left->val;
        }
        if(node->right){
            count-=node->right->val;
            if(treaversal(node->right,count))   return true;
            count+=node->right->val;
        }
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root==nullptr)   return false;
        return treaversal(root,targetSum-root->val);
    }
};
