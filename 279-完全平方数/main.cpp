#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


//  类似于背包问题，硬币问题。
//  给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

// https://leetcode-cn.com/problems/perfect-squares/solution/chao-zhi-bai-kao-zui-jiang-xiao-xue-sheng-du-neng-/
class Solution {
public:
    int numSquares(int n) {
        vector<int> vetResult(n +1, INT32_MAX);
        vetResult[0] = 0;
        for (int i = 1; i <= n; i++) {
            for(int j = 1; i - j * j  >=0 ;j++) {
                vetResult[i] = min(vetResult[i], vetResult[i- j * j] +1);
            }
        }
        return vetResult[n];
    }
};


// 时间复杂度：O(n*sqrt(n))
// 空间复杂度：O(n)