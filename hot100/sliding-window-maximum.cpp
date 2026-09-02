#include<iostream>
#include<queue>
#include<vector>

class Solution{
public:
	std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k){
		std::vector<int> res;
		std::deque<int>  window;
		for(int right=0;right<nums.size();++right){
			int left=right-k+1;
			if(!window.empty()&&window.front()<left)
				window.pop_front();
			while(!window.empty()&&nums[window.back()]<nums[right])
				window.pop_back();
			window.push_back(right);
			if(left>=0)
				res.push_back(nums[window.front()]);
		}
		return res;
	}
};


int main(){
	std::cout<<"vector's size"<<std::endl;
	int n;	std::cin>>n;
	std::vector<int> nums(n);
	std::cout<<"vector's elements"<<std::endl;
	for(int i=0;i<n;++i)
		std::cin>>nums[i];
	std::cout<<"windows's size"<<std::endl;
	int k;	std::cin>>k;
	Solution solution;
	std::vector<int>res = solution.maxSlidingWindow(nums,k);
	for(auto& i:res){
		std::cout<<i<<" ";
	}
	return 0;
}
