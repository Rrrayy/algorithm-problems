#include<iostream>
#include<vector>

class Solution{
public:
	int maxArea(std::vector<int>& height){
		int left=0;
		int right=height.size()-1;
		int area=0;
		while(left<right){
			int width=right-left;
			int Height=std::min(height[left],height[right]);
			area=std::max(area,width*Height);
			if(height[left]<height[right])
				left++;
			else
				right--;
		}
		return area;
	}
};


int main(){
	int n;
	std::cout<<"vector's size"<<std::endl;
	std::cin>>n;
	std::vector<int> height(n);
	std::cout<<"vector's element"<<std::endl;
	for(int i=0;i<n;++i)
		std::cin>>height[i];
	Solution solution;
	int res = solution.maxArea(height);
	std::cout<<res;
	return res;
}
