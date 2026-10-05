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
    void treaversal(TreeNode* node,vector<TreeNode*>& vec){
        if(node==nullptr) return ;
        vec.push_back(node);
        treaversal(node->left,vec);
        treaversal(node->right,vec);
    }
    void flatten(TreeNode* root) {
        if(root==nullptr)
            return ;
        vector<TreeNode*>vec;
        treaversal(root,vec);
        for(int i=0;i<vec.size()-1;++i){
            vec[i]->left=nullptr;
            vec[i]->right=vec[i+1];
        }
        vec.back()->left=nullptr;
        vec.back()->right=nullptr;
    }
};