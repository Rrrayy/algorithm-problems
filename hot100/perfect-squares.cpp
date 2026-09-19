class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1,n);
        dp[0]=0;
        for(int j=1;j<=n;++j){
            for(int k=1;k*k<=j;++k)
                dp[j]=min(dp[j],dp[j-k*k]+1);
        }
        return dp[n];
    }
};
