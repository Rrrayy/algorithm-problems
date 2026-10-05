#include<iostream>
#include<vector>

int partition(std::vector<int>& nums, int left ,int right){
    int pivot = nums[right];
    int i = left-1 ;
    for(int j=left ;j<right ; ++j){
        if(nums[j]<pivot){
            ++i;
            std::swap(nums[i],nums[j]);
        }
    }
    std::swap(nums[i+1],nums[right]);
    return i+1;
}

void quick_sort(std::vector<int>& nums, int left ,int right){
    if(nums.size()==0)  return ;
    if(left>=right)
        return ;
    int pivot = partition(nums, left ,right);
    quick_sort(nums, left ,pivot-1);
    quick_sort(nums, pivot+1, right);
}

int main(int argc ,char** argv){
    std::vector<int> exp = {1,4,5,21,6,56,8,32,112};
    quick_sort(exp,0,exp.size()-1);
    for(auto i: exp){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
