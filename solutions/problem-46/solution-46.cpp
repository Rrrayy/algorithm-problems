class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    void dfs(vector<int>& nums, vector<bool>& t){
        if(path.size()==nums.size()){
            res.push_back(path);
            return ;
        }
        for(int i=0;i<nums.size();++i){
            if(t[i]==true)
                continue;
            t[i]=true;
            path.push_back(nums[i]);
            dfs(nums,t);
            path.pop_back();
            t[i]=false;
        }

    }
    vector<vector<int>> permute(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool>t(nums.size(),false);
        dfs(nums,t);
        return res;
    }
};
