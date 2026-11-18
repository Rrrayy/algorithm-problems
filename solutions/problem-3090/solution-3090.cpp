class Solution {
public:
    int maximumLengthSubstring(string s) {
        int st[26]={0};
        int left=0,res=0;
        for(int right=0;right<s.size();++right){
            ++st[s[right]-'a'];
            while(st[s[right]-'a']>2){
                st[s[left]-'a']--;
                left++;
            }
            res=max(res,right-left+1);
        }
        return res;
    }
};