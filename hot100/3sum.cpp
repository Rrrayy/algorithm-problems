#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
public:
	std::vector<std::vector<int>> threeSum(std::vector<int>& nums){
		std::sort(nums.begin(),nums.end());
		std::vector<std::vector<int>> res;
		for(int i=0;i<nums.size()-2;++i){
			if(nums[i]>0)
				return res;
			if(i>0&&nums[i]==nums[i-1])
				continue;
			int l=i+1;
			int r=nums.size()-1;
			while(l<r){
				if(nums[i]+nums[l]+nums[r]>0){
					r--;
				}
				else if(nums[i]+nums[r]+nums[l]<0){
					l++;
				}
				else{
					res.push_back({nums[i],nums[l],nums[r]});
					while(l<r&&nums[l]==nums[l+1])	l++;
					while(l<r&&nums[r]==nums[r-1])	r--;
					l++;
					r--;
				}
			}
		}
		return res;
	}
};

int main(){
	int n;
	std::cout<<"vector's size"<<std::endl;
	std::cin>>n;
	std::vector<int> nums(n);
	std::cout<<"vector's elements"<<std::endl;
	for(int i=0;i<n;++i){
		std::cin>>nums[i];
	}

	Solution solution;
	std::vector<std::vector<int>> res = solution.threeSum(nums);
	for(auto i: res){
		for(auto j :i )
			std::cout<< j<<" ";
		std::cout<<std::endl;
	}

	return 0;
}
