#include<iostream>
#include<vector>
#include<random>

static std::random_device rd;
static std::mt19937 gen(rd());
int partation(std::vector<int>& nums, int left ,int right){
    std::uniform_int_distribution<int> dis(left, right);
    int ranindex = dis(gen);
    std::swap(nums[ranindex],nums[right]);
    int pivot = nums[right];
    int i =left- 1;
    for(int j=left ;j<right ;++j){
        if(nums[j]<pivot){
            ++i;
            std::swap(nums[i],nums[j]);
        }
    }
    std::swap(nums[i+1],nums[right]);
    return i+1;
}

void quick_sort(std::vector<int>&nums , int left ,int right){
    if(nums.size()==0)  return;
    if(left>=right) return ;
    int index = partation(nums,left,right);
    quick_sort(nums,left,index-1);
    quick_sort(nums,index+1,right);
}

int main(int argc, char** argv){
    std::vector<int>tmp = {1,3,4,66,1341,6234,6321};
    quick_sort(tmp, 0 ,tmp.size()-1);
    for(auto& i : tmp)
        std::cout<<i<<" ";
    std::cout<<std::endl;
    return 0;
}
