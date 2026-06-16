//注意写reverse函数中的min函数不可写成 reverse(s.begin()+i,s.begin()+min(i+k,s.size()))
//s.size()返回的是std::string::size_type 即使无符号size_t类型
//而min函数时模板函数，要求两个参数是同一T类型,所以将s.size()隐式转换成int类型进行比较
//若严谨点防止潜在溢出,可使用static_cast<T>进行显式转换

class Solution {
public:
    string reverseStr(string s, int k) {
        int size=s.size();
        for(int i=0;i<s.size();i+=(2*k)){
            //reverse(s.begin()+i,s.begin()+min(i+k,size));
             reverse(s.begin()+i,s.begin()+min((i+k),static_cast<int>(s.size())));
        }
        return s;
    }
};
