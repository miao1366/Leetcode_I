#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

//  你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。
//  同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
//  给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额

class Solution {
public:
    int rob(vector<int>& nums) {
        if (nums.size() == 1 ) return nums[0];
        return max(max_(nums, 0, nums.size()-1), max_(nums, 1, nums.size()));
    }

    int max_(vector<int>& nums, int start, int end) {
        int ans = 0;
        int tmp = 0;
        int pre = 0;
        for (;start < end; ++start) {
            tmp = ans;
            ans = max(ans, pre + nums[start]);
            pre = tmp;
        }
        return ans;
    }
    
};