/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        queue<Node*>q;
        vector<vector<int>>res;
        if(root)
            q.push(root);
        while(!q.empty()){
            int size=q.size();
            vector<int>temp;
            for(int i=0;i<size;++i){
                Node* node=q.front();
                q.pop();
                temp.push_back(node->val);
                for(int j=0;j<node->children.size();++j)
                    if(node->children[j])
                        q.push(node->children[j]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
