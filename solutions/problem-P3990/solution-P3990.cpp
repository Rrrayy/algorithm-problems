#include<vector>
#include<iostream>
#include<cstdint>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    std::vector<int>nums;
    int n;  std::cin>>n;
    for(int i=0;i<n;++i){
      std::cin>>nums[i];
    }
    int64_t sum=0;
    for(auto j:nums){
        sum+=j;
    }
    std::cout<<sum;
    return 0;
}
