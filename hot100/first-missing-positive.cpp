#include<iostream>
#include<vector>

class Solution{
public:
	int firstMissingPositive(std::vector<int>& nums){
		int length=nums.size();
		for(int i=0;i<length;++i){
			while(true){
				int cur=nums[i];
				if(cur<=0||cur>=length)	break;
				int correct_index =cur-1;
				if(nums[correct_index]==cur)	break;
				std::swap(nums[correct_index],nums[i]);
			}
		}
		for(int i=0;i<length;++i){
			if(nums[i]!=i+1)
				return i+1;
		}
		return length+1;
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
	Solution so;
	int res=so.firstMissingPositive(nums);
	std::cout<<res;
}
