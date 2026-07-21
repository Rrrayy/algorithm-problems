/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*>q;
        if(root)
            q.push(root);
        while(!q.empty()){
            int size=q.size();
            Node* node;Node* cur;
            for(int i=0;i<size;++i){
                if(i==0){
                    cur=q.front();q.pop();
                    node=cur;
                }
                else{
                    node=q.front();q.pop();
                    cur->next=node;
                    cur=cur->next;
                }
                if(node->left)  q.push(node->left);
                if(node->right) q.push(node->right);
            }
            cur->next=NULL;
        }
        return root;
    }
};
