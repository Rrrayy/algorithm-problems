class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int n=arr.size();
        if(n<k) return 0;
        int sum=0;
        int res=0;
        for(int i=0;i<k;++i){
            sum+=arr[i];
        }
        if(sum>=k*threshold)    res++;
        for(int i=1;i<=n-k;++i){
            sum+=arr[i+k-1]-arr[i-1];
            if(sum>=k*threshold)
                res++;
        }
        return res;
    }
};