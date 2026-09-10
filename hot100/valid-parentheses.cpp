#include<iostream>
#include<string>
#include<stack>

class Solution {
public:
    bool isValid(std::string s) {
        if(s.size() % 2 != 0)   return false;
        std::stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] == '(')   st.push(')');
            else if(s[i] == '[')  st.push(']');
            else if(s[i] == '{')   st.push('}');
            else if(st.empty() || st.top() != s[i]) return false;
            else st.pop();
        }
        return st.empty();
    }
};

int main(){
    std::cout << "input string" << std::endl;
    std::string s;
    std::cin >> s;

    Solution so;
    bool res = so.isValid(s);
    std::cout << (res ? "true" : "false") << std::endl;

    return 0;
}