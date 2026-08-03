class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void dfs(int tar,int k,int n ,int start){
        if(n>tar)
            return ;
        if(path.size()==k){
            if(n==tar)  res.push_back(path);
            return;
        }
        for(int i=start;i<=9-(k-path.size())+1;++i){
            n+=i;
            path.push_back(i);
            dfs(tar,k,n,i+1);
            n-=i;
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(n,k,0,1);
        return res;      
    }
};
