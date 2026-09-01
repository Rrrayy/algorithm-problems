#include<iostream>
#include<string>
#include<vector>

class Solution{
public:
    std::vector<int> findAnagrams(std::string s, std::string p){
		std::vector<int> res;
		if(s.size()<p.size()){
			return res;
		}
		std::vector<int> a(26,0);
		std::vector<int> b(26,0);
		for(int i=0;i<p.size();++i){
			++a[s[i]-'a'];
			++b[p[i]-'a'];
		}
		if(a==b)
			res.push_back(0);
		for(int right=p.size();right<s.size();++right){
			int left=right-p.size();
			--a[s[left]-'a'];
			++a[s[right]-'a'];
			if(a==b)
				res.push_back(left+1);
		}
		return res;
	}
};

int main(){
	std::cout<<"input original string"<<std::endl;
	std::string s;
	std::cin>>s;
	std::cout<<"input target string"<<std::endl;
	std::string p;
	std::cin>>p;
	Solution solution;
	std::vector<int>res=solution.findAnagrams(s,p);
	for(auto &i:res){
		std::cout<<i<<" ";
	}
	return 0;
}
