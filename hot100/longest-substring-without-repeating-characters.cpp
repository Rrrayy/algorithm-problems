#include<iostream>
#include<unordered_set>
#include<string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<int> set;
		int left=0;
		int max_len=0;
		for(int right=0;right<s.size();++right){
			while(set.count(s[right])){
				set.erase(s[left]);
				++left;	
			}
			set.insert(s[right]);
			int cur_len=right-left+1;
			max_len=std::max(max_len,cur_len);
		}
	return max_len;
    }
};


int main(){
	std::string s;
	std::cout<<"input string"<<std::endl;
	std::cin>>s;
	Solution solution;
	int res=solution.lengthOfLongestSubstring(s);
	std::cout<<res;
	return 0;
}
