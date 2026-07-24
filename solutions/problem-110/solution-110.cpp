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
    int get(TreeNode* node){
        if(node==nullptr)   return 0;
        int left=get(node->left);
        if(left==-1) return -1;
        int right = get(node->right);
        if(right==-1) return -1;
        return abs(left-right)>1?-1:1+max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        return get(root)==-1?false:true;      
    }
};
