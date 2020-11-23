#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。
// 岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。
// 此外，你可以假设该网格的四条边均被水包围。


class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        m_row = grid.size();
        m_column = grid[0].size();
        int sum = 0;
        for(int i = 0; i < m_row; ++i) {
            for (int j = 0; j < m_column; ++j) {
                if(grid[i][j] == '1') {
                    ++sum;
                    dfs(i, j, grid);
                }
            }
        }
        return sum;
    }

    void dfs(int i, int j, vector<vector<char>>& grid) {
        
        grid[i][j] = '0';
        if(i-1 >= 0 && grid[i-1][j] == '1') {
            dfs(i-1, j, grid);
        }
        if(i+1 < m_row && grid[i+1][j] == '1') {
            dfs(i+1, j, grid);
        }
        if(j-1 >= 0 && grid[i][j-1] == '1') {
            dfs(i, j-1, grid);
        }
        if(j+1 < m_column  && grid[i][j+1] == '1') {
            dfs(i, j+1, grid);
        }
        
    }

    int m_row;
    int m_column;
};

//   时间复杂度：O(MN)，其中 MM 和 NN 分别为行数和列数。
//   空间复杂度：O(MN)，在最坏情况下，整个网格均为陆地，深度优先搜索的深度达到 M NMN。

int main() {
    vector<vector<char>> grid {{'1', '1', '1', '1', '0'}, {'1', '1', '0', '1', '0'}, {'1', '1', '0', '0', '0'}, {'0', '0', '0', '0', '0'}};
    Solution sn;
    cout << sn.numIslands(grid) <<endl;
}