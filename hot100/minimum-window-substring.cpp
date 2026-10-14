class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int>need,window;
        for(char c:t)   need[c]++;
        int left=0; int right=0;
        int count=0;
        int len=INT_MAX; int start=0;
        while(right<s.size()){
            char i =s[right];
            right++;
            if(need.count(i)){
                window[i]++;
                if(need[i]==window[i])
                    count++;
            }
            while(count==need.size()){
                if(right-left<len){
                    len=right-left;
                    start=left;
                }
                char d=s[left];
                left++;
                if(need.count(d)){
                    if(window[d]==need[d])
                        count--;
                    window[d]--;
                }
            }
        }
        return len<INT_MAX?s.substr(start,len):"";
    }
};