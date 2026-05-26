//时间复杂度为O(nlogk)
//map操作为O(logk)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        map<char,int>mp;
        int res=0;
        for(auto i=0;i<word.length();++i){
            if(word[i]>='a'&&word[i]<='z'){
                mp[word[i]]=1;
            } 
        }
        map<char,bool>mp1;
        for(auto i=0;i<word.length();++i){
            if(word[i]>='A'&&word[i]<='Z'){
                if(mp.count(word[i]+32)&&!mp1.count(word[i]+32)){
                    res++;
                    mp1[word[i]+32]=true;
                }
            }
        }
        return res;
    }
};
