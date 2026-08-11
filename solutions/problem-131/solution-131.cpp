class Solution {
public:
    vector<string> path;
    vector<vector<string>>  res;
    bool isPalindrome(string &s,int start , int end){
        for(int i =start , j=end ;i<j; i++, j--){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    void dfs(string& s , int startindex){
        if(startindex>=s.size()){
            res.push_back(path);
            return ;
        }
        for(int i=startindex ;i<s.size();++i){
            if(isPalindrome(s,startindex,i)){
                string str =s.substr(startindex,i-startindex+1);
                path.push_back(str);
            }
            else    continue;
            dfs(s,i+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        path.clear();
        res.clear();
        dfs(s,0);
        return res;
    }
};
