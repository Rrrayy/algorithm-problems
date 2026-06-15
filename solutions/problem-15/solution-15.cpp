//先确定一个数，再运用双指针收缩左或右边界使得总和接近或等于0
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>res;
        //O(n)时间复杂度的排序函数，若排序后数组第一个元素大于0，则返回空数组
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(nums[i]>0)
                return res;
            //避免出现重复的结果数组首元素进而使得结果重复    
            if(i>0&&nums[i]==nums[i-1])
                continue;
            int l=i+1;
            int r=nums.size()-1;
            while(l<r){
                if(nums[i]+nums[l]+nums[r]<0)
                    l++;
                else if(nums[i]+nums[l]+nums[r]>0)
                    r--;
                else{
                    res.push_back(vector<int>{nums[i],nums[l],nums[r]});
                    //先存入结果，再在该条件下进行重复筛选，防止遗漏答案
                    while(l<r&&nums[r]==nums[r-1])
                        r--;
                    while(l<r&&nums[l]==nums[l+1])
                        l++;
                    r--;
                    l++;     
                }
            }
        }
        return res;
    }
};
