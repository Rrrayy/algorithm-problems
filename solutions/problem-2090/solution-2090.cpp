class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        if(k==0)
            return nums;
        int n=static_cast<int>(nums.size());
        vector<int>res(n,-1);
        if(2*k+1>n) return res;
        long long  sum=0;
        for(int i=0;i<=2*k;++i){
            sum+=nums[i];
        }
        res[k]=sum/(2*k+1);
        for(int i=1;i<=2*k+i&&i<n-2*k;++i){
            sum+=nums[2*k+i]-nums[i-1];
            res[k+i]=sum/(2*k+1);
        }
        return res;
    }
};