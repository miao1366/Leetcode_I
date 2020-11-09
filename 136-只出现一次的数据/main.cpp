
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了两次。找出那个只出现了一次的元素。
// 说明：
// 你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

// https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-shu-zi-dian-lu-she/
// https://leetcode-cn.com/problems/single-number-ii/solution/zhi-chu-xian-yi-ci-de-shu-zi-ii-by-leetcode/


// v1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        size_t numsSize = nums.size();
        for(size_t i = 0; i < numsSize -1;) {
            if(nums[i] != nums[i+1]) {
                return nums[i];
            }
            i += 2;
        }
        return nums.back();
    }
    
};


// 
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0;
        for (auto e: nums) ret ^= e;
        return ret;
    }
};

// 时间复杂度：O(n)，其中 n 是数组长度。只需要对数组遍历一次。
// 空间复杂度：O(1) 
