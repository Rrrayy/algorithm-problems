class Solution {
public:
    bool istrue(char ch){
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
    }
    int maxVowels(string s, int k) {
        int res=0;
        int count=0;
        for(int i=0;i<k;++i){
            count+=istrue(s[i]);
        }
        res=max(res,count);
        for(int i=k;i<s.size();++i){
            count+=istrue(s[i])-istrue(s[i-k]);
            res=max(count,res);
        }
        return res;
    }
};