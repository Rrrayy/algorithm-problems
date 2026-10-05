class Solution {
public:
    int partition(vector<int>& nums,int left,int right){
        int randomindex=left+rand()%(right-left+1);
        swap(nums[randomindex],nums[right]);
        int pivot=nums[right];
        int i=left;
        for(int j=left;j<right;++j){
            if(nums[j]<pivot){
                swap(nums[j],nums[i]);
                ++i;
            }
        }
        swap(nums[i],nums[right]);
        return i;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int tar=n-k;
        int left=0,right=n-1;
        while(true){
            int pivot=partition(nums,left,right);
            if(pivot==tar)  return nums[pivot];
            else if(pivot>tar)  right=pivot-1;
            else    left=pivot+1;
        }
    }
};