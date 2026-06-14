//将四重循环优化成两重循环
//运用unordered_map结构，用count记录总和-两数之和及nums[0-c-d]的个数
class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> nums;
        for(auto a:nums1){
            for(auto b:nums2){
                nums[a+b]++;
            }
        }
        int count=0;
        for(auto c:nums3){
            for(auto d:nums4){
                if(nums.find(0-(c+d))!=nums.end())
                    count+=nums[0-c-d];
            }
        }
        return count;
    }
};
