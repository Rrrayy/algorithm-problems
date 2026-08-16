class Solution {
public:
    vector<vector<int>>res;
    vector<int> path;
    void dfs(vector<int>& nums,vector<bool>& t){
        if(path.size()==nums.size()){
            res.push_back(path);
            return;
        }
        for(int i=0;i<nums.size();++i){
            if(i>0 && nums[i]==nums[i-1]&&t[i-1]==false)
                continue;
            if(t[i]==false){
                path.push_back(nums[i]);
                t[i]=true;
                dfs(nums,t);
                t[i]=false;
                path.pop_back();
                }
            }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        res.clear();
        path.clear();
        vector<bool> t(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,t);
        return res;
    }
};
