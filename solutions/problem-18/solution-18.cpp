//原理和三数之和一样，运用双指针，只不过该题多嵌套了一个循环并多了一次去重操作
//本题存在整形溢出问题，当四数之和过大是转型成long long 与原target比较则可通过
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();++i){
            if(i>0&&nums[i]==nums[i-1])
                continue;
            for(int k=i+1;k<nums.size();++k){
                if(k>i+1&&nums[k]==nums[k-1])
                    continue;
                int l=k+1;
                int r=nums.size()-1;
                while(l<r){
                    long long sum=(long long )nums[i]+nums[k]+nums[l]+nums[r];
                    if(sum<target)
                        l++;
                    else if(sum>target)
                        r--;
                    else{
                        res.push_back(vector<int>{nums[i],nums[k],nums[l],nums[r]});
                        while(l<r&&nums[l]==nums[l+1]) l++;
                        while(l<r&&nums[r]==nums[r-1]) r--;
                        r--;
                        l++;
                    }
                }    
            }
        }
        return res;
    }
};
