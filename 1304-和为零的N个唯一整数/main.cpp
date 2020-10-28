#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

//给你一个整数 n，请你返回 任意 一个由 n 个 各不相同 的整数组成的数组，并且这 n 个数相加和为 0 。

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> vetRet(n);
        int times = (n +1) / 2;
        int middle = n / 2;
        for(int i = 0; i < times; i++) {
          vetRet[i] = -middle;
          vetRet[n-i-1] = middle;
          middle--;
        }
        return vetRet;
    }
};


//   0   1   2   3      2
//  -2   -1  1   2
     
//  0  1   2  3  4    3  
// -2 -1  0  1  2