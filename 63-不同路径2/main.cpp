#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// v1
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        size_t row = obstacleGrid.size();
        size_t column = obstacleGrid[0].size();
        vector<vector<int> >  grid(row, vector<int>(column, 0));
        grid[0][0] = obstacleGrid[0][0] ? 0 : 1;
        for(size_t i = 1; i < row; ++i) {
            grid[i][0] = obstacleGrid[i][0] ? 0 : grid[i-1][0]; 
        }

        for(size_t i = 1; i < column; ++i) {
            grid[0][i] = obstacleGrid[0][i]  ? 0 : grid[0][i - 1];
        }

        for(size_t i = 1; i < row; ++i) {
            for (size_t j = 1; j < column; ++j) {
                grid[i][j] = obstacleGrid[i][j]  ? 0 : grid[i-1][j] + grid[i][j-1];
            }
        }
        return grid[row-1][column-1];
    }
};