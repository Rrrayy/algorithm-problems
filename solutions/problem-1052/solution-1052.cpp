class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int res=0,base=0;
        for(int i=0;i<grumpy.size();++i){
            if(grumpy[i]==0)
                base+=customers[i];
        }
        int gain=0;
        for(int i=0;i<minutes;++i){
            if(grumpy[i]==1){
                gain+=customers[i];
            }
        }
        res=gain;
        for(int i=1;i<=customers.size()-minutes;++i){
            if(grumpy[i-1]==1)
                gain-=customers[i-1];
            if(grumpy[i+minutes-1]==1)
                gain+=customers[i+minutes-1];
            res=max(gain,res);
        }
        
        return base+res;
    }
};