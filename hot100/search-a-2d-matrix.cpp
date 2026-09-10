#include<iostream>
#include<vector>

class Solution{
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = 0;
        int right = m * n - 1;
        while(left <= right){
            int mid = left + (right - left) / 2;
            if(matrix[mid/n][mid%n] < target) left = mid + 1;
            else if(matrix[mid/n][mid%n] == target) return true;
            else right = mid - 1;
        }
        return false;
    }
};

int main(){
    int m, n;
    std::cout << "input matrix's rows and cols" << std::endl;
    std::cin >> m >> n;

    std::vector<std::vector<int>> matrix(m, std::vector<int>(n));
    std::cout << "input matrix's elements" << std::endl;
    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];

    std::cout << "input target" << std::endl;
    int target; std::cin >> target;

    Solution so;
    bool res = so.searchMatrix(matrix, target);
    std::cout << (res ? "true" : "false") << std::endl;

    return 0;
}
