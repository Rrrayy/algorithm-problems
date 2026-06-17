//KMP算法，可使用前缀表直接构造next数组。若next数组末尾元素不为0，则说明有重复前后缀
//但本题要判断字符串是否由重复子串组成，所以字符串长度%(字符串长度-最长的相等前后缀长度)应该==0

class Solution {
public:
    void Next(vector<int>arr,string s){
        arr[0]=0;
        int j=0;
        for(int i=1;i<s.size();++i){
            while(j>0&&s[j]!=s[i]){
                j=arr[j-1];
            }
            if(s[j]==s[i])
                j++;
            arr[i]=j;
        }
    }
    bool repeatedSubstringPattern(string s) {
        if(s.size()==0)
            return false;
        vector<int>arr(s.size());
        Next(arr,s);
        int len =static_cast<int>(s.size());
        if(arr[len-1]!=0&&len%(len-arr[len-1])==0)
            return true;
        return false;
    }
};
