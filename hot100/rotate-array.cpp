#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
public:
	void rotate(std::vector<int>& nums, int k) {
		if(nums.size()<=1)
			return ;
		if(nums.size()>static_cast<size_t>(k))
			k=k%(static_cast<int>(nums.size()));
		std::reverse(nums.begin(),nums.end());
		std::reverse(nums.begin(),nums.begin()+k);
		std::reverse(nums.begin()+k,nums.end());
	}
};


int main(){
	int n;
	std::cout<<"input array's size"<<std::endl;
	std::cin>>n;
	std::vector<int>nums(n);
	std::cout<<"vector's elements"<<std::endl;
	for(int i=0;i<n;++i)
		std::cin>>nums[i];
	int k;	std::cout<<"input pos"<<std::endl;
	std::cin>>k;
	Solution so;
	so.rotate(nums,k);
	for(auto i :nums)
		std::cout<<i<<" ";
	return 0;
}
