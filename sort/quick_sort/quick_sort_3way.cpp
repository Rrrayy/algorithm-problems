#include<iostream>
#include<vector>
#include<cstdlib>
#include<utility>

std::pair<int,int> partation(std::vector<int>& nums, int left ,int right){
    int rand_index = left+rand()%(right-left+1);
    std::swap(nums[rand_index],nums[left]);
    int pivot = nums[left];
    int lt= left;
    int rt = right;
    int i =left+1;
    while(i<=rt){
        if(nums[i]<pivot){
            std::swap(nums[i],nums[lt]);
            lt++;
            i++;
        }else if(nums[i]>pivot){
            std::swap(nums[i],nums[rt]);
            rt--;
        }
        else{
            i++;
        }
    }
    //std::swap(nums[lt],nums[left]);
    return {lt,rt};
}

void quick_sort(std::vector<int>&nums, int left ,int right){
    if(nums.size()==0)  return;
    if(left>=right) return ;
    auto [lt,rt] = partation(nums,left,right);
    quick_sort(nums,left,lt-1);
    quick_sort(nums,rt+1,right);
}

int main(int argc , char** argv){
    std::vector<int> tmp = {1,23,4,312,53,46,2424};
    quick_sort(tmp,0,tmp.size()-1);
    for(auto& i : tmp){
        std::cout<<i<<" ";
    }
    std::cout<<std::endl;
    return 0;
}
