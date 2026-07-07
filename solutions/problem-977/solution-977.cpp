class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        //O(nlogn)解法
        //for(int i=0;i<nums.size();++i){
        //    nums[i]*=nums[i];
        //}
        //sort(nums.begin(),nums.end());

        //O(n)解法
        vector<int>res(nums.size());
        int left=0;
        int right=nums.size()-1;
        int index=nums.size()-1;
        while(left<=right){
            int l=nums[left]*nums[left];
            int r=nums[right]*nums[right];
            if(l>r){
                res[index]=l;
                left++;
            }
            else{
                res[index]=r;
                right--;
            }
            index--;
        }
        return res;
    }
};
