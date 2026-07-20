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
    /*
    void treaval(TreeNode* node, vector<int>&nodes){
        if(node==nullptr)  
            return;
        treaval(node->left,nodes);
        treaval(node->right,nodes);
        nodes.push_back(node->val);
    }
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>res;
        treaval(root,res);
        return res;
    }
    */
    vector<int> postorderTraversal(TreeNode* root){
        vector<int>res;
        stack<TreeNode*>st;
        if(root==nullptr)
            return res;
        st.push(root);
        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();
            res.push_back(node->val);
            if(node->left) st.push(node->left);
            if(node->right)  st.push(node->right);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};
