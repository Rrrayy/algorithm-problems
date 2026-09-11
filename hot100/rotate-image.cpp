#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        for(int i = 0; i < matrix.size(); ++i){
            for(int j = i + 1; j < matrix.size(); ++j)
                std::swap(matrix[i][j], matrix[j][i]);
        }

        for(int i = 0; i < matrix.size(); ++i){
            int left = 0;
            int right = matrix[0].size() - 1;
            while(left <= right){
                std::swap(matrix[i][left], matrix[i][right]);
                left++;
                right--;
            }
        }
    }
};

int main(){
    int n;
    std::cout << "input matrix's size" << std::endl;
    std::cin >> n;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(n));
    std::cout << "input matrix's elements" << std::endl;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < n; ++j)
            std::cin >> matrix[i][j];

    Solution so;
    so.rotate(matrix);

    std::cout << "rotated matrix:" << std::endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j)
            std::cout << matrix[i][j] << " ";
        std::cout << std::endl;
    }

    return 0;
}