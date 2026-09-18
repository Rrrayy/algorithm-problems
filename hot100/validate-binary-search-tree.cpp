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
    bool dfs(TreeNode* node ,TreeNode* minnode,TreeNode* maxnode){
        if(!node)   return true;
        if(minnode && node->val<=minnode->val)  return false;
        if(maxnode && node->val>=maxnode->val)  return false;
        return dfs(node->left,minnode,node)&&dfs(node->right,node,maxnode);
    }
    bool isValidBST(TreeNode* root) {
        return dfs(root,nullptr,nullptr);
    }
};
