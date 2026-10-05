//找第 k 大元素，平均 O(n)
#include<vector>
#include<cstdlib>

class Solution{
	public:
		int findKLargest(std::vector<int>& nums,int k){
			int n=nums.size();
			int tar=n-k;
			int left=0,right=n-1;
			while (true){
				int pivot=partition(nums,left,right);
				if(pivot==tar)	return nums[pivot];
				else if(pivot<tar)	left=pivot+1;
				else	right=pivot-1;
			}
		}
	private:
		int partition(std::vector<int>& nums,int left,int right){
			int randomindex=left+rand()%(right-left+1);
			std::swap(nums[right],nums[randomindex]);
			int pivot=nums[right];
			int i=left;
			for(int j=left;j<right;++j){
				if(nums[j]<pivot){
					std::swap(nums[i],nums[j]);
					i++;
				}
			}
			std::swap(nums[i],nums[right]);
			return i;
		}
};