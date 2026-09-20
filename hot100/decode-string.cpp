class Solution {
public:
    string decodeString(string s) {
        stack<int> nums;
        stack<string> str;
        string cur="";
        int num=0;
        for(char c :s){
            if(isdigit(c))
                num=num*10+(c-'0');
            else if(c=='['){
                nums.push(num);
                str.push(cur);
                num=0;
                cur="";
            }
            else if(c==']'){
                int k=nums.top();   nums.pop();
                string prev=str.top();  str.pop();
                string temp=""; 
                for(int i=0;i<k;++i){
                    temp+=cur;
                }
                cur=prev+temp;
            }
            else{
                cur+=c;
            }
            
        }
        return cur;
    }
};
