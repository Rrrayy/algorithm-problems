class Solution {
public:
    vector<string> path;
    vector<vector<string>> res;
    bool ispalindrome(string &s,int begin,int end){
        for(int i=begin,j=end;i<j;++i,--j){
            if(s[i]!=s[j])
                return false;
        }
        return true;
    }
    void dfs(string &s,int startindex){
        if(startindex==s.size()){
            res.push_back(path);
            return;
        }
        for(int i=startindex;i<s.size();++i){
            if(ispalindrome(s,startindex,i)){
                path.push_back(s.substr(startindex,i-startindex+1));
            }
            else    continue;
            dfs(s,i+1);
            path.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        dfs(s,0);
        return res;
    }
};