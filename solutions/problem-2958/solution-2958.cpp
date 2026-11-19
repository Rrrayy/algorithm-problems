class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int left=0,res=0;
        unordered_map<int,int> mp;
        for(int right=0;right<nums.size();++right){
            ++mp[nums[right]];
            while(mp[nums[right]]>k){
                --mp[nums[left]];
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};