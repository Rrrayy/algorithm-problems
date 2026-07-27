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
    vector<vector<int>>res;
    vector<int>path;
    void traversal(TreeNode* node, int count){
        if(node->left==nullptr&&node->right==nullptr&&count==0){
            res.push_back(path);
            return;
        }
        if(node->left==nullptr&&node->right==nullptr)   return;
        if(node->left){
            path.push_back(node->left->val);
            count-=node->left->val;
            traversal(node->left,count);
            count+=node->left->val;
            path.pop_back();
        }
        if(node->right){
            path.push_back(node->right->val);
            count-=node->right->val;
            traversal(node->right,count);
            count+=node->right->val;
            path.pop_back();
        }
        return ;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        res.clear();path.clear();
        if(root==nullptr)   return res;
        path.push_back(root->val);
        traversal(root,targetSum-root->val);
        return res;      
    }
};
