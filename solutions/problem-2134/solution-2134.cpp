class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int k=0;
        int n=nums.size();
        for(int i=0;i<n;++i)
            if(nums[i]==1)
                k++;
        if(k==0||k==1)
            return 0;
        vector<int> newnums=nums;
        newnums.insert(newnums.end(),nums.begin(),nums.end());
        int count=0,res=0;
        for(int i=0;i<k;++i){
            if(newnums[i]==0)
                count++;
        }
        res=count;
        for(int i=1;i<=n-1;++i){
            if(newnums[i-1]==0) count--;
            if(newnums[i+k-1]==0)   count++;
            res=min(count,res);
        }
        return res;
    }
};