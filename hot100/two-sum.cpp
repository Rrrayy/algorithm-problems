#include<iostream>
#include<vector>
#include<unordered_map>

class Solution{
    public:
    std::vector<int> twoSum(std::vector<int> &nums, int target){
        std::unordered_map<int,int>mp;
        for(int i=0;i<nums.size();++i){
            auto it =mp.find(target-nums[i]);
            if(it!=mp.end())
                return {it->second,i};
            mp[nums[i]]=i;
        }
        return {};
    }
};

int main(){
    int n;
	int target;

	std::cout<<"input array size:"<<std::endl;
	std::cin>>n;

	std::vector<int> nums(n);

	std::cout<<"input array elements:"<<std::endl;
	for(int i=0;i<n;++i){
		std::cin>>nums[i];
	}

	std::cout<<"input target:"<<std::endl;
	std::cin>>target;

	Solution solution;
	std::vector<int> result=solution.twoSum(nums,target);

	if(!result.empty()){
		std::cout<<result[0]<<" "<<result[1]<<std::endl;
	}else{
		std::cout<<"no result"<<std::endl;
	}

	return 0;
}
