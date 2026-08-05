class Solution {
public:
    const string lettermap[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string>res;
    string s;
    void dfs(string digits,int index){
        if(index==digits.size()){
            res.push_back(s);
            return ;
        }
        int cur = digits[index]-'0';
        string letter = lettermap[cur];
        for(int i=0;i<letter.size();++i){
            s.push_back(letter[i]);
            dfs(digits,index+1);
            s.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        s.clear();res.clear();
        if(digits.size()==0)
            return res;
        dfs(digits,0);
        return res;
    }
};
