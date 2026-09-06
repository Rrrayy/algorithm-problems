#include <iostream>
#include <vector>

class Solution{
public:
	std::vector<int> productExceptSelf(std::vector<int>& nums){
		std::vector<int> res(nums.size(),1);
		for(int i=1;i<nums.size();++i){
			res[i]=res[i-1]*nums[i-1];
		}
		int right_sum=1;
		for(int i=nums.size()-1;i>=0;--i){
			res[i]*=right_sum;
			right_sum*=nums[i];
		}
		return res;
	}
};

int main(){
	std::cout<<"vector's size"<<std::endl;
	int n; std::cin>>n;
	std::vector<int>nums(n);
	std::cout<<"vector's elements"<<std::endl;
	for(int i=0;i<n;++i)
		std::cin>>nums[i];
	Solution so;
	std::vector<int> res =so.productExceptSelf(nums);
	for(auto i:res){
		std::cout<<i<<" ";
	}
	return 1;
}
