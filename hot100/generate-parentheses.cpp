class Solution {
public:
    vector<string> res;
    void dfs(int n ,int l ,int r, string path){
        if(path.size()==2*n){
            res.push_back(path);
            return ;
        } 

        if(l<n){
            path.push_back('(');
            dfs(n,l+1,r,path);
            path.pop_back();
        }

        if(r<l){
            path.push_back(')');
            dfs(n,l,r+1,path);
            path.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string path="";
        dfs(n,0,0,path);
        return res;
    }
};