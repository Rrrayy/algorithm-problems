class Solution {
public:
    int dir[4][2]={0,1,1,0,-1,0,0,-1};
    bool dfs(vector<vector<char>>& board,vector<vector<bool>>& visited,string& word,int x ,int y, int index){
        if(x<0||x>=board.size()||y<0||y>=board[0].size()||visited[x][y]||board[x][y]!=word[index])
            return false;
        if(index==word.size()-1)
            return true;
        visited[x][y]=true;
        for(int i=0;i<4;++i){
            int nx=x+dir[i][0];
            int ny=y+dir[i][1];
            if(dfs(board,visited,word,nx,ny,index+1))
                return true;
        }
        visited[x][y]=false;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>>visited(board.size(),vector<bool>(board[0].size(),false));
        for(int i=0;i<board.size();++i){
            for(int j=0;j<board[0].size();++j){
                if(dfs(board,visited,word,i,j,0))
                    return true;
            }
        }
        return false;
    }
};