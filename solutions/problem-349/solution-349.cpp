//运用std::unordered_set结构
//底层实现是哈希表并且不允许存在重复数据

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> result;
        unordered_set<int> nums(nums1.begin(),nums1.end());
        for(int num:nums2){
            if(nums.find(num)!=nums.end())
                result.insert(num);
        }
        return vector<int>(result.begin(),result.end());
    }
};
