class Solution {
public:
    vector<vector<int>>res;
    vector<int>path;
    void dfs(vector<int>& nums,int startindex){
        if(path.size()>1)
            res.push_back(path);
        unordered_set<int> used;
        for(int i=startindex;i<nums.size();++i){
            if(used.count(nums[i]))
                continue;
            if(!path.empty()&&nums[i]<path.back()) 
                continue ;
            path.push_back(nums[i]);
            used.insert(nums[i]);
            dfs(nums,i+1);
            path.pop_back();

        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
       path.clear();
       res.clear();
       dfs(nums,0);
       return res; 
    }  
};
