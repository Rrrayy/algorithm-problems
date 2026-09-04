#include<iostream>
#include<vector>
#include<algorithm>
class Solution{
public:
	std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals){
		std::vector<std::vector<int>>res;
		if(intervals.empty())
			return res;
		std::sort(intervals.begin(),intervals.end(),[](const std::vector<int>&a ,const std::vector<int>&b){return a[0]<b[0];});
		res.push_back(intervals[0]);
		for(int i=1;i<intervals.size();++i){
			if(intervals[i][0]<=res.back()[1])
				res.back()[1]=std::max(intervals[i][1],res.back()[1]);
			else 
				res.push_back(intervals[i]);
		}
		return res;
	} 
};


int main(){
	Solution sol;
    int n;
	std::cout<<"vector's size:"<<std::endl;
    std::cin >> n; 

    std::vector<std::vector<int>> intervals(n, std::vector<int>(2));
    for (int i = 0; i < n; ++i) {
        std::cin >> intervals[i][0] >> intervals[i][1];
    }

    std::vector<std::vector<int>> res = sol.merge(intervals);

    for (const auto& interval : res) {
        std::cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    std::cout << std::endl;

    return 0;
	
}
