#include<iostream>
#include<vector>

class Solution{
public:
	int maxSubArray(std::vector<int>& nums){
		int cur_sum=nums[0];
		int max_sum=nums[0];
		for(int i=1;i<nums.size();++i){
			cur_sum=std::max(nums[i],cur_sum+nums[i]);
			max_sum=std::max(cur_sum,max_sum);
		}
		return max_sum;
	}
};


int main(){
	std::cout<<"vector's size"<<std::endl;
	int n;	std::cin>>n;
	std::cout<<"vector's elements"<<std::endl;
	std::vector<int> nums(n);
	for(int i=0;i<n;++i)
		std::cin>>nums[i];
	Solution soluiton;
	int res=soluiton.maxSubArray(nums);
	std::cout<<res;
	return res;
}
