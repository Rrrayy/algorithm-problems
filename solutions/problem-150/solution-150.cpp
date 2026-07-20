class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        char math[4]={'+','-','*','/'};
        stack<int> st;
        int res=0;
        for(auto c:tokens){
            bool isop=false;
            for(int i=0;i<4;++i){
                if(c.size()==1&&c[0]==math[i]){
                    int num1=st.top();st.pop();
                    int num2=st.top();st.pop();
                    switch(i){
                        case 0 : {res=num2+num1; break;}
                        case 1 : {res=num2-num1; break;}
                        case 2 : {res=num2*num1; break;}
                        case 3 : {res=num2/num1; break;}
                    }
                    st.push(res);
                    isop=true;
                    break;
                }
            }
            if(isop==false)
                st.push(stoi(c));    
        }   
        return st.top();
    }
};
