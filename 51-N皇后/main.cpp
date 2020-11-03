#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;



// https://leetcode-cn.com/problems/n-queens/solution/nhuang-hou-jing-dian-hui-su-suan-fa-tu-wen-xiang-j/  这个题解挺好的



// v1

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        m_n = n;
        solveNQueens(1,vector<string>());
        return vetRet;
    }

    void solveNQueens(int row, vector<string> vetStr) {
        if (row == m_n) {
            vetRet.push_back(vetStr);
        }



    }

private:
    // 检查如果第row行 第column列插入字符是否合法， vetStr的size = row -1
    bool valid(int row, int column, const vector<string> &vetStr) {
        //检查上方是否有皇后
        for(int i = 1; i < row; i++) {
            if (vetStr[i-1][column-1] == 'Q') {
                return false;
            }
        }
        //检查左上方是否有皇后
        int time = 0;
        for(int i = column - 1; i >= 1; i--) {
            time++;
            if (vetStr[row-1-time][column-1-time] == 'Q') {
                return false;
            }
        }

        //检查右上方是否有皇后
        time = 0;
        for(int i = column + 1; i <= m_n; i++) {
            time++;
            if (vetStr[row-1-time][column-1+time] == 'Q') {
                return false;
            }
        }
   

        return true;
    }

    vector<vector<string>> vetRet;
    int m_n;
};























class Solution {
public:
    vector<vector<string>> ans;
    vector<string> track;
    vector<int> vt;
    vector<vector<string>> solveNQueens(int n) {
        for (int i = 0; i < n; i++) {
            track.push_back(string(n, '.'));
        }
        backtracking(0, n);
        return ans;
    }
    void backtracking(int r, int n) {
        if (r == n) {
            ans.push_back(track);
            return;
        }
        for (int i = 0; i < n; i++) {
            if (!check(r, i, n)) continue;
            track[r][i] = 'Q';
            vt.push_back(i);
            backtracking(r + 1, n);
            track[r][i] = '.';
            vt.pop_back();
        }
    }
    bool check(int r, int c, int n){
        for (int i = 0; i < r; i++) {
            if (vt[i] == c || r + c == i + vt[i] || r - c == i - vt[i])
                return false;
        }
        return true;
    }
};

int main() {
    return 0;
}
