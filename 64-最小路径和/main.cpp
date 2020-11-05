#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


// 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
// 说明：每次只能向下或者向右移动一步。
// 示例:

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t row = grid.size();
        size_t column = grid[0].size();
        vector<vector<int> >  minPathGrid(row, vector<int>(column, 0));
        minPathGrid[0][0] = grid[0][0];
        for(size_t i = 1; i < row; ++i) {
            minPathGrid[i][0] = grid[i][0] + minPathGrid[i-1][0]; 
        }

        for(size_t i = 1; i < column; ++i) {
            minPathGrid[0][i] = grid[0][i] + minPathGrid[0][i - 1];
        }

        for(size_t i = 1; i < row; ++i) {
            for (size_t j = 1; j < column; ++j) {
                minPathGrid[i][j] = grid[i][j] + min(minPathGrid[i-1][j], minPathGrid[i][j-1]);
            }
        }
        return minPathGrid[row-1][column-1];
    }
    
};