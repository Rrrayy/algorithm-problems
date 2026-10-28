class Solution {
public:
    vector<vector<string>>res;
    bool isValid(int row,int col,vector<string>&temp,int n){
        for(int i=0;i<row;++i){
            if(temp[i][col]=='Q')
                return false;
        }
        for(int i=row-1,j=col-1;i>=0&&j>=0;--i,--j){
            if(temp[i][j]=='Q')
                return false;
        }
        for(int i=row-1,j=col+1;i>=0&&j<n;--i,++j){
            if(temp[i][j]=='Q')
                return false;
        }
        return true;
    }
    void dfs(int n,int row,vector<string>&temp){
        if(row==n){
            res.push_back(temp);
            return;
        }
        for(int col=0;col<n;++col){
            if(isValid(row,col,temp,n)){
                temp[row][col]='Q';
                dfs(n,row+1,temp);
                temp[row][col]='.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string>temp(n,string(n,'.'));
        dfs(n,0,temp);
        return res;
    }
};