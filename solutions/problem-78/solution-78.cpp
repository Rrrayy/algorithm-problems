class Solution {
public:
    vector<vector<int>>res;
    vector<int> path;
    void dfs(vector<int>& nums,int startindex){
        res.push_back(path);
        if(startindex>=nums.size()){
            return ;
        }
        for(int i=startindex;i<nums.size();++i){
            path.push_back(nums[i]);
            dfs(nums,i+1);
            path.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        res.clear();
        path.clear();
        dfs(nums,0);
        return res;
    }
};
