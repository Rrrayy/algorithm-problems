//基础O(n^2)实现
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //O(n2)
        for(int i=0;i<nums.size();++i){
            for(int j=i+1;j<nums.size();++j){
                if(nums[j]==target-nums[i])
                    return {i,j};
            }
        }
        return {};
    }
};
//unordered_map哈希实现O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();++i){
            auto it=mp.find(target-nums[i]);
            if(it!=mp.end())
                return {it->second,i};
            mp[nums[i]]=i;
        }
        return {};
    }
};
