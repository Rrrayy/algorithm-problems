class Solution {
public:
    int trap(vector<int>& height) {
        int left=0;
        int right=height.size()-1;
        int res=0;
        int leftmax=0;int rightmax=0;
        while(left<right){
            leftmax=max(leftmax,height[left]);
            rightmax=max(rightmax,height[right]);
            if(leftmax<rightmax){
                res+=leftmax-height[left];
                left++;
            }
            else{
                res+=rightmax-height[right];
                right--;
            }
        }
        return res;
    }
};