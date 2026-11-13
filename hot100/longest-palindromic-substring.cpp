class Solution {
public:
    pair<int,int> expand(const string&s,int left,int right){
        while(left>=0&&right<s.size()&&s[left]==s[right]){
            --left;
            ++right;
        }      
        return{left+1,right-1}; 
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int begin=0;
        int end=0;
        for(int i=0;i<n;++i){
            auto[l1,r1]=expand(s,i,i);
            if(r1-l1>end-begin){
                begin=l1;
                end=r1;
            }
            auto[l2,r2]=expand(s,i,i+1);
            if(r2-l2>end-begin){
                begin=l2;
                end=r2;
            }
        }
        string res=s.substr(begin,end-begin+1);
        return res;
    }
};