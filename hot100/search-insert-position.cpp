#include<iostream>
#include<vector>

class Solution{
public:
	int searchInsert(std::vector<int>& nums, int target){
		int left=0;
		int right=nums.size();
		while(left<right){
			int mid=(left+right)/2;
			if(target<nums[mid])	right=mid-1;
			else if(target>nums[mid])	left=mid+1;
			else if(target==nums[mid])	return mid;
		}
		return target<=nums[left]?left:left+1;
	}
};


int main(){
	int n;
	std::cout<<"input vector's size"<<std::endl;
	std::cin>>n;
	std::vector<int> nums(n);
	std::cout<<"input vectos's elements"<<std::endl;
	for(int i=0;i<n;++i)
		std::cin>>nums[i];
	Solution so;
	std::cout<<"input target"<<std::endl;
	int target; std::cin>>target;
	int pos = so.searchInsert(nums,target);
	std::cout<<pos;
}
