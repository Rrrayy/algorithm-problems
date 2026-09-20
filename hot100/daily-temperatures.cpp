class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n=static_cast<int>(temperatures.size());
        stack<int>st;
        vector<int>res(n,0);
        for(int i=0;i<n;++i){
            while(!st.empty()&&temperatures[st.top()]<temperatures[i]){
                int prev=st.top();
                st.pop();
                res[prev]=i-prev;
            }
            st.push(i);
        }
        return res;
    }
};
