class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>res;
        int left=0;
        int right=matrix[0].size()-1;
        int up=0;
        int down=matrix.size()-1;

        while(true){
            for(int i=left;i<=right;++i)
                res.push_back(matrix[up][i]);
            if(++up>down)   break;
            for(int j=up;j<=down;++j)
                res.push_back(matrix[j][right]);
            if(--right<left)    break;
            for(int i=right;i>=left;--i)
                res.push_back(matrix[down][i]);
            if(--down<up)   break;
            for(int j=down;j>=up;--j)
                res.push_back(matrix[j][left]);
            if(++left>right)    break;
        }
        return res;
    }
};
