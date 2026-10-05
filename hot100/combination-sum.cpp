class Solution {
public:
    vector<int>path;
    vector<vector<int>>res;
    void dfs(vector<int>& nums,int target,int sum,int start){
        if(sum==target){
            res.push_back(path);
            return;
        }
        for(int i=start;i<nums.size();++i){
            if(sum+nums[i]<=target){
                path.push_back(nums[i]);
                sum+=nums[i];
                dfs(nums,target,sum,i);
                sum-=nums[i];
                path.pop_back();
            }
            else 
                continue;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates,target,0,0);
        return res;
    }
};