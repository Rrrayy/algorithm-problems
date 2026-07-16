class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int res=0;
        int left=0;
        int nums[128];
        memset(nums,-1,sizeof(nums));
        for(int right=0;right<s.size();right++){
            if(nums[s[right]]!=-1&&nums[s[right]]>=left){
                left=nums[s[right]]+1;
            }
            nums[s[right]]=right;
            res=max(res,right-left+1);
        }
        return res;
    }
};
