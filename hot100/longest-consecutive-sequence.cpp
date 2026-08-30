#include<iostream>
#include<unordered_set>
#include<vector>

class Solution{
public:
	int longgetConsecutive(std::vector<int>& nums){
		std::unordered_set<int> nums_set(nums.begin(),nums.end());
		int max_len =0;
		for(auto& num : nums){
			if(!nums_set.count(num-1)){
				int curnum=num;
				int curlen=1;
				while(nums_set.count(curnum+1)){
					curlen++;
					curnum++;
				}
				max_len=std::max(max_len,curlen);
			}
		}
		return max_len;
	}
};

int main(){
	Solution solution;
	std::cout<<"vector's size: "<<std::endl;
	int n;
	std::cin>>n;
	std::vector<int> nums(n);
	std::cout<<"vector's elements"<<std::endl;
	for(int i=0;i<n;++i){
		std::cin>>nums[i];
	}
	int res=solution.longgetConsecutive(nums);
	std::cout<<res;
	return res;
}
