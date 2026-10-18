class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int count=0;
        int res=0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]==2)
                    q.push({i,j});
                else if(grid[i][j]==1)
                    count++;
            }
        }
        int dir[4][2]={0,1,0,-1,-1,0,1,0};
        while(!q.empty()&&count>0){
            int size=q.size();
            res++;
            while(size--){
                pair<int,int>cur=q.front();
                q.pop();
                for(int i=0;i<4;++i){
                    int nextx=cur.first+dir[i][0];
                    int nexty=cur.second+dir[i][1];
                    if(nextx<0||nextx>=grid.size()||nexty<0||nexty>=grid[0].size()||grid[nextx][nexty]!=1)    continue;
                    grid[nextx][nexty]=2;
                    q.push({nextx,nexty});
                    --count;
                }
            }
        }
        return count==0?res:-1;
    }
};