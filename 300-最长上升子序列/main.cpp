#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;


//给定一个无序的整数数组，找到其中最长上升子序列的长度。

// v1  xx
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        vector<int> lengthLIS(nums.size(), 1);
        for(size_t i = 1; i < nums.size(); i++) {
            lengthLIS[i] = lengthLIS[i-1] + (nums[i] > nums[i -1] ? 1 : 0);
        }
        std::sort(lengthLIS.begin(), lengthLIS.end());
        return lengthLIS[nums.size()-1];
    }
};

//v2 https://leetcode-cn.com/problems/longest-increasing-subsequence/solution/dong-tai-gui-hua-er-fen-cha-zhao-tan-xin-suan-fa-p/
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size() < 2) return nums.size();
        vector<int> lengthLIS(nums.size(), 1);
        for(size_t i = 1; i < nums.size(); i++) {
            for(size_t j = 0; j < i; j++) {
                if(nums[i]>nums[j]) {
                    lengthLIS[i] = max(lengthLIS[i], lengthLIS[j] + 1);
                }
            }
            
        }
        std::sort(lengthLIS.begin(), lengthLIS.end());
        return lengthLIS[nums.size()-1];
    }
};
//   时间复杂度：O(N^2)O(N 
//   空间复杂度：O(N)O(N)