#include<iostream>
#include<vector>

class Solution{
public:
    int search(std::vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])    left = mid + 1;
            else    right = mid;
        }
        int index = left;
        if(target >= nums[index] && target <= nums[nums.size() - 1])
            left = index, right = nums.size() - 1;
        else
            left = 0, right = index - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)   return mid;
            else if(nums[mid] < target)   left = mid + 1;
            else    right = mid - 1;
        }
        return -1;
    }
};

int main(){
    int n;
    std::cout << "input vector's size" << std::endl;
    std::cin >> n;

    std::vector<int> nums(n);
    std::cout << "input vector's elements" << std::endl;
    for(int i = 0; i < n; ++i)
        std::cin >> nums[i];

    std::cout << "input target" << std::endl;
    int target; std::cin >> target;

    Solution so;
    int pos = so.search(nums, target);
    std::cout << pos << std::endl;

    return 0;
}