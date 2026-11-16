class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        long long sum=0;
        long long res=0;
        int dup=0;
        for(int i=0;i<k;++i){
            mp[nums[i]]++;
            if(mp[nums[i]]==2)
                dup++;
            sum+=nums[i];
        }
        if(dup==0)
            res=max(res,sum);
        for(int i=1;i<=nums.size()-k;++i){
            sum-=nums[i-1];
            if(--mp[nums[i-1]]==1)
                dup--;
            if(mp[nums[i-1]]==0)
                mp.erase(nums[i-1]);
            sum+=nums[i+k-1];
            if(++mp[nums[i+k-1]]==2)
                dup++;
            if(dup==0)
                res=max(res,sum);
        }
        return res;
    }
};