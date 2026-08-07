  class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void dfs(vector<int>& candidates, int target , int sum , int startindex){
        if(sum>target)
            return;
        if(sum==target){
            res.push_back(path);
            return ;
        }
        for(int i=startindex;i<candidates.size(); ++i){
            if(i>startindex&&candidates[ i]==candidates[i-1])
                continue;
            if(sum+candidates[i]>target)
                break;
            path.push_back(candidates[i]);
            sum+=candidates[i];
            dfs(candidates,target,sum,i+1);
            sum-=candidates[i];
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        path.clear();
        res.clear();
        sort(candidates.begin(),candidates.end());
        dfs(candidates,target,0,0);
        return res;
    }
};
