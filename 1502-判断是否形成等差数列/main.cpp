#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// 给你一个数字数组 arr 。
// 如果一个数列中，任意相邻两项的差总等于同一个常数，那么这个数列就称为 等差数列 。
// 如果可以重新排列数组形成等差数列，请返回 true ；否则，返回 false 。

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        std::sort(arr.begin(), arr.end());
        if (arr.size() < 2) {
            return true;
        }
        int differernt = arr[1] - arr[0];
        for(size_t i = 2; i < arr.size(); i++) {
            if(arr[i]-arr[i-1] != differernt) {
                return false;
            }    
        }
        return true;
    }
};