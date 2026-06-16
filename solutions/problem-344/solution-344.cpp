//时间复杂度O(n),空间复杂度O(1)
//本题也可用std::reverse()函数实现同一效果
//for循环内简化可用std::swap()函数

class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size()==0)
            return;
        for(int i=0,j=s.size()-1;i<j;i++,j--){
            char temp=s[j];
            s[j]=s[i];
            s[i]=temp;
        }
    }
};
