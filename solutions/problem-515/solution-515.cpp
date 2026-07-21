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
    vector<int> largestValues(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int>res;
        if(root)
            q.push(root);
        while(!q.empty()){
            int num=INT_MIN;
            int size=q.size();
            for(int i=0;i<size;++i){
                TreeNode* node=q.front();
                q.pop();
                num=max(num,node->val);
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(num);
        }
        return res;
    }
};
