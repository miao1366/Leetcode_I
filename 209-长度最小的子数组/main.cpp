#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续 子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。


// v1 failed
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), [](const int &a, const int &b ){ return a > b;});
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
           sum += nums[i];
           if (sum >= s) {
               return i + 1;
           }
        }
        return 0;
    }
};