class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int left=0,res=0,sum=0;
        unordered_set<int> st;
        for(int right=0;right<nums.size();++right){
            while(st.count(nums[right])){
                st.erase(nums[left]);
                sum-=nums[left];
                left++;
            }
            st.insert(nums[right]);
            sum+=nums[right]; 
            res=max(res,sum); 
        }
        return res;
    }
};