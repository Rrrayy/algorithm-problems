#include<iostream>
#include<vector>
#include<algorithm>

class Solution{
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        auto l = lower_bound(nums.begin(), nums.end(), target);
        auto r = upper_bound(nums.begin(), nums.end(), target);
        if(l == nums.end() || *l != target)
            return {-1, -1};
        return {static_cast<int>(l - nums.begin()), static_cast<int>(r - nums.begin()) - 1};
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
    std::vector<int> res = so.searchRange(nums, target);

    std::cout << "[" << res[0] << ", " << res[1] << "]" << std::endl;

    return 0;
}
