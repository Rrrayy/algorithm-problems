class Solution {
public:
    void sortColors(vector<int>& nums) {
        //sort(nums.begin(),nums.end());

        // int zero=0,one=0,two=0;
        // int n=static_cast<int>(nums.size());
        // for(int i=0;i<n;++i){
        //     if(nums[i]==0)  zero++;
        //     else if(nums[i]==1) one++;
        //     else two++;
        // }
        // int index=0;
        // for(int i=0;i<zero;++i){    
        //     nums[index]=0;
        //     index++;
        // }
        // for(int i=0;i<one;++i){
        //     nums[index]=1;
        //     index++;
        // }
        // for(int i=0;i<two;++i){
        //     nums[index]=2;
        //     index++;
        // }
        
        int low=0,mid=0,high=nums.size()-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[mid],nums[low]);
                low++;
                mid++;
            }
            else if(nums[mid]==1)
                mid++;
            else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }     
    }   
};
