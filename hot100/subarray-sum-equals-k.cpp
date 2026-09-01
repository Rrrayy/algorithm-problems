#include<iostream>
#include<vector>
#include<unordered_map>

class Solution{
public:
	int subarraySum(std::vector<int>& nums, int k){
		std::unordered_map<int,int> prefix_count;
		int prefix=0;
		int count=0;
		prefix_count[0]=1;
		for(auto& i:nums){
			prefix+=i;
			auto it=prefix_count.find(prefix-k);
			if(it !=prefix_count.end())
				count+=it->second;
			prefix_count[prefix]++;
		}
		return count;
	}
};


int main(){
	std::cout<<"input vector's size"<<std::endl;
	int n; std::cin>>n;
	std::vector<int> nums(n);
	std::cout<<"input vector's elements"<<std::endl;
	for(int i=0;i<n;++i)
		std::cin>>nums[i];
	std::cout<<"input target"<<std::endl;
	int k; std::cin>>k;
	Solution solution;
	int res=solution.subarraySum(nums,k);
	std::cout<<"------------------------------------"<<std::endl;
	std::cout<<res<<std::endl;
	return res;
}
