#include <iostream>
#include <vector>
#include <string>
using namespace std;

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