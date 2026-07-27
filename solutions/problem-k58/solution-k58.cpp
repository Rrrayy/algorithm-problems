#include<iostream>
#include<vector>
using namespace std;
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int n,a,b,sum;
    cin>>n;
    sum=0;
    vector<int>nums(n);
    vector<int>prefix(n);
    for(int i=0;i<n;++i){
        cin>>nums[i];
        sum+=nums[i];
        prefix[i]=sum;
    }
    while(cin>>a>>b){
        if(a==0)    cout<<prefix[b]<<endl;
        else    cout<<prefix[b]-prefix[a-1]<<endl;
    }
    return 0;
}
