#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>
#include<algorithm>

class Solution{
	public:
	std::vector<std::vector<std::string>> groupAngrams(std::vector<std::string>& strs){
		std::unordered_map<std::string,std::vector<std::string>> mp;
		for(int i=0 ;i<strs.size(); ++i){
			std::string key =strs[i];
			std::sort(key.begin(),key.end());
			mp[key].push_back(strs[i]);
		}
		std::vector<std::vector<std::string>> res;
		for(auto& i : mp){
			res.push_back(i.second);
		}
		return res;
	}
};
int main(){
	int n;
	std::cout<<"get vector's size"<<std::endl;
	std::cin>>n;
	std::vector<std::string> strs(n);
	for(int i=0;i<n;++i){
		std::cin>>strs[i];
	}
	Solution solution;
	std::vector<std::vector<std::string>> res = solution.groupAngrams(strs);
	for(auto &i:res){
		std::cout<<"[";
		for(auto &j :i){
			std::cout<<j<<" ";
		}
		std::cout<<"] ";
	}
	return 0;
}
