class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void dfs(vector<int>& nums, int startindex, vector<bool>& used){
        res.push_back(path);
        for(int i=startindex;i<nums.size();++i){
            if(i>0&&nums[i-1]==nums[i]&&used[i-1]==false){
                continue;
            }
            path.push_back(nums[i]);
            used[i]=true;
            dfs(nums,i+1,used);
            path.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        res.clear();path.clear();
        vector<bool> used(nums.size(),false);
        sort(nums.begin(),nums.end());
        dfs(nums,0,used);
        return res;
    }
};
