#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

// https://leetcode-cn.com/problems/unique-paths/

// https://leetcode-cn.com/problems/unique-paths/solution/c-dpji-bai-100-z-by-zrita/  题解


// v1   41/62通过测试用例    最后超出时间  递归会超时
class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m <= 1 || n <= 1) {
            return 1;
        }
        
        return uniquePaths(m-1, n) + uniquePaths(m, n-1);
    }
};



// v2 https://leetcode-cn.com/problems/unique-paths/solution/c-dpji-bai-100-z-by-zrita/      时间:o(mn) 空间:o(mn)
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int> > grid(m, std::vector<int>(n, 1));
        for (int i = 2; i <= m; i++) {
            for (int j = 2; j <= n; j++) {
                grid[i-1][j-1] = grid[i-2][j-1] + grid[i-1][j-2];
            }
        }
        return grid[m-1][n-1];
    }
};


// v2 https://leetcode-cn.com/problems/unique-paths/solution/c-dpji-bai-100-z-by-zrita/      时间:o(m*n) 空间:o(n)
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> cur(n, 1);
        for (int i = 1; i < m; i++) 
            for (int j = 1; j < n; j++) 
                cur[j] += cur[j - 1];
        return cur[n - 1];
    }
};


// v3 https://leetcode-cn.com/problems/unique-paths/solution/c-dpji-bai-100-z-by-zrita/     时间:o(min(m, n)) 空间:o(1)
class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n + m - 2;
        int k = min(m - 1, n - 1);
        long long res = 1;
        for (int i = 1; i <= k; i++)
            res = res * (N - k + i) / i;
        return (int) res;
    }
};



