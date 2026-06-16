//整体翻转+局部翻转
//先去除多余空格然后进行总体翻转，再通过空格作为标记，进行对每个单词的翻转

class Solution {
public:
    string reverseWords(string s) {
        int slow=0;
        for(int fast=0;fast<s.size();fast++){
            if(s[fast]!=' '){
                if(slow!=0)
                    s[slow++]=' ';
                while(fast<s.size()&&s[fast]!=' '){
                    s[slow++]=s[fast++];
                }
            }
        }
        s.resize(slow);
        reverse(s.begin(),s.end());
        int start=0;
        for(int index=0;index<=s.size();++index){
            if(index==s.size()||s[index]==' '){
                reverse(s.begin()+start,s.begin()+index);
                start=index+1;
            }
        }
        return s;
    }
};
