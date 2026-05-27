//单层for循环实现O(n)的时间复杂度
//滑动窗口：右指针不断扩展右窗口直到窗口内和大于target->记录长度并收缩左窗口
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0;
        int l=0;
        int res=INT_MAX;
        for(int r=0;r<nums.size();++r){
            sum+=nums[r];
            while(sum>=target){
                res=min(res,(r-l+1));
                sum-=nums[l];
                l++;
            }
        }
        return res==INT_MAX?0:res;
    }
};
