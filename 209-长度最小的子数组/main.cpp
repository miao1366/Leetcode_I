#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


// 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s 的长度最小的 连续子数组，并返回其长度。如果不存在符合条件的子数组，返回 0。
  

// v1 failed 超出时间限制  重复了很多计算 时间复杂度比o(n^2) 还高
// class Solution {
// public:
//     int minSubArrayLen(int s, vector<int>& nums) {
//         for (int i = 0; i < nums.size(); i++) {
//             if (findSubArray(s, nums, i + 1)) {
//                 return i + 1;
//             }
//         }
//         return 0;
//     }

//     bool findSubArray(int s, vector<int>& nums, int subSize) {
//         int InumsSize = nums.size();
//         for(int i = 0; i <= InumsSize - subSize; i++) {
//            int sum = 0;
//            for (int j = 0; j < subSize; j++) {
//                sum += nums[i+j];
//            }
//            if (sum >= s) {
//                return true;
//            }  
//         }
//         return false;
//     }
// };



// v1 改进版本
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int ans = INT32_MAX;
        int InumsSize = nums.size();
        for (int i = 0; i < InumsSize; i++) {
            int sum =0;
            for (int j=i; j< InumsSize; j++) {
                sum += nums[j];
                if (sum >= s) {
                    ans = min(ans, j - i + 1);
                    break;
                }
            }
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};
// 时间复杂度 o(n^2)

// 双指针法    https://leetcode-cn.com/problems/minimum-size-subarray-sum/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-43/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int left = 0;
        int right = 0;
        int sum = 0;
        int ans = INT32_MAX;
        while (right < n) {
            sum += nums[right];
            right++;
            while (sum >= s) {
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT32_MAX ? 0 : ans;
    }
};
//    时间复杂度：O(n)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return 0;
        }
        int ans = INT32_MAX;
        int left =  0;
        int right = 0;
        int sum =   0;
        while (right < n) {
            sum += nums[right++];
            while (sum >= s) {
                ans = min(ans, right - left);
                sum -= nums[left];
                left++;
            }
        }
        return ans == INT32_MAX ? 0 : ans; 

    }
};









