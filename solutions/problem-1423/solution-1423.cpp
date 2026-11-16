class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        int windowsum=0;
        int total=0;
        for(auto x:cardPoints)
            total+=x;
        int len=n-k;    
        if(len==0)
            return total;
        for(int i=0;i<len;++i)
            windowsum+=cardPoints[i];
        int sum=windowsum;
        for(int i=1;i<=k;++i){
            windowsum-=cardPoints[i-1];
            windowsum+=cardPoints[len+i-1];
            sum=min(windowsum,sum);
        }
        return total-sum;
    }
};