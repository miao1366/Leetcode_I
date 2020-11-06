#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// 根据 百度百科 ，生命游戏，简称为生命，是英国数学家约翰·何顿·康威在 1970 年发明的细胞自动机。
// 给定一个包含 m × n 个格子的面板，每一个格子都可以看成是一个细胞。每个细胞都具有一个初始状态：1 即为活细胞（live），或 0 即为死细胞（dead）。每个细胞与其八个相邻位置（水平，垂直，对角线）的细胞都遵循以下四条生存定律：
// 如果活细胞周围八个位置的活细胞数少于两个，则该位置活细胞死亡；
// 如果活细胞周围八个位置有两个或三个活细胞，则该位置活细胞仍然存活；
// 如果活细胞周围八个位置有超过三个活细胞，则该位置活细胞死亡；
// 如果死细胞周围正好有三个活细胞，则该位置死细胞复活；
// 根据当前状态，写一个函数来计算面板上所有细胞的下一个（一次更新后的）状态。下一个状态是通过将上述规则同时应用于当前状态下的每个细胞所形成的，其中细胞的出生和死亡是同时发生的。

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        bool live[9] = {false, false, true, true, false, false, false, false, false}; 
        bool death[9] = {false, false, false, true, false, false, false, false, false}; 
        size_t row = board.size();
        size_t column = board[0].size();
        vector<vector<int> > vetBoard(row+2, vector<int>(column+2,0));
        for(size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < column; j++) {
                vetBoard[i+1][j+1] = board[i][j];
            }
        }
        for(size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < column; j++) {
                int liveNums = getLiveNums(i, j, vetBoard);
                board[i][j] = (board[i][j] ? live[liveNums]:death[liveNums]) ? 1 : 0;
                }
            }
    }
    
    int getLiveNums(int x, int y, const vector<vector<int> > & vet) {
        ++x;
        ++y;
        return vet[x][y-1] + vet[x][y+1] + vet[x-1][y] + vet[x+1][y] + vet[x-1][y-1] + vet[x-1][y+1] + vet[x+1][y-1] + vet[x+1][y+1]; 
    }
};