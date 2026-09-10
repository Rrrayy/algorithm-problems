#include<iostream>
#include<vector>

class Solution{
public:
    int findMin(std::vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while(left < right){
            int mid = left + (right - left) / 2;
            if(nums[mid] > nums[right])   left = mid + 1;
            else    right = mid;
        }
        return nums[left];
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

    Solution so;
    int res = so.findMin(nums);
    std::cout << res << std::endl;

    return 0;
}