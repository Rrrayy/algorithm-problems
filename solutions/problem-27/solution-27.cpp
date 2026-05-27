//数组中的元素在内存地址上是连续的
//不能单独删除某个元素，只能进行覆盖
//O(n^2)暴力解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size=nums.size();
        for(int i=0;i<size;++i){
            if(nums[i]==val){
                for(int j=i+1;j<size;++j){
                    nums[j-1]=nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }
};

//双指针O(n)解法
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow=0;
        for(int fast=0;fast<nums.size();fast++){
            if(nums[fast]!=val){
              //nums[slow++]=nums[fast];
                nums[slow]=nums[fast];
                slow++;
            }
        }
        return slow;
    }
};
