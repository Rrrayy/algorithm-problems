class Solution {
public:
    int getNext(int x){
        int sum=0;
        while(x>0){
            int i=x%10;
            sum+=i*i;
            x=x/10;
        }
        return sum;
    }
    bool isHappy(int n) {
        int slow=n;
        int fast=getNext(n);
        while(fast!=1&&fast!=slow){
            slow=getNext(slow);
            fast=getNext(getNext(fast));
        }
        return fast==1;
    }
};
