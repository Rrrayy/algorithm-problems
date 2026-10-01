class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res=0;
        int temp=INT_MAX;
        for(int i=0;i<prices.size();++i){
            temp=min(temp,prices[i]);
            res=max(res,(prices[i]-temp));
        }
        return res;
    }
};
