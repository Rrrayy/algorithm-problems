class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxlen=0;
        int n=static_cast<int>(nums.size())-1;
        for(int i=0;i<=n;++i){
            if(i>maxlen)    return false;
            maxlen=max(maxlen,i+nums[i]);
            if(maxlen>=n)
                return true;
        }
        return false;
    }
};
