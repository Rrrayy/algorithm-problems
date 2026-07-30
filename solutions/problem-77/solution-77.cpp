class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void dfs(int n,int k,int start){
        if(path.size()==k){
            res.push_back(path);
            return ;
        }
        for(int i=start;i<=n-(k-path.size())+1;++i){
            path.push_back(i);
            dfs(n,k,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n,k,1);
        return res;
    }
};
