class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size()<=1)  return 0;
        int res=0;
        int maxlen=0;
        int cur=0;
        int n=static_cast<int>(nums.size())-1;
        for(int i=0;i<=n;++i){
            maxlen=max(maxlen,nums[i]+i);
            if(i==cur){
                res++;
                cur=maxlen;
                if(cur>=n)    return res;
            }
        }
        return res;     
    }
};
