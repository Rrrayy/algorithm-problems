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
    TreeNode* traversal(vector<int>& preorder, vector<int>& inorder){
        if(preorder.empty()) return nullptr;
        int value=preorder[0];
        TreeNode* root = new TreeNode(value);
        int k=0;
        while(inorder[k]!=value)    k++;
        vector<int> leftinorder(inorder.begin(),inorder.begin()+k);
        vector<int> rightinorder(inorder.begin()+k+1,inorder.end());
        int leftsize=k;
        vector<int> leftpreorder(preorder.begin()+1,preorder.begin()+1+leftsize);
        vector<int> rightpreorder(preorder.begin()+1+leftsize,preorder.end());
        root->left=traversal(leftpreorder,leftinorder);
        root->right=traversal(rightpreorder,rightinorder);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0|inorder.size()==0)    return NULL;
        return traversal(preorder,inorder);
    }
};