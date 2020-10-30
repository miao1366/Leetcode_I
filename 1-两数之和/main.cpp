#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// 给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
// 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

// v1
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vetRet;
        if(nums.size() < 2) {
            return vetRet;
        } 
        for(size_t i = 0; i < nums.size(); i++) {
            for(size_t j = 0; j < nums.size(); j++) {
                if(i == j) {
                    continue;
                }
                if(nums[i] + nums[j] == target) {
                    vetRet.push_back(i);
                    vetRet.push_back(j);
                    return vetRet;
                }
            }
        }
        return vetRet;
    }
};


// v2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vetRet;
        map<int, int> mapNums;
        if(nums.size() < 2) {
            return vetRet;
        }

        for(size_t i = 0; i < nums.size(); i++) {
            if(mapNums.find(target-nums[i]) != mapNums.end()) {
                vetRet.push_back(i);
                vetRet.push_back(mapNums[target-nums[i]]);
                return vetRet;
            }
            mapNums[nums[i]] = i;    
        }
        return vetRet;
    }
};

// v2
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> vetRet;
        map<int, int> mapNums;
        if(nums.size() < 2) {
            return vetRet;
        }

        for(size_t i = 0; i < nums.size(); i++) {
            if(mapNums.count(target-nums[i]) != 0) {
                vetRet.push_back(i);
                vetRet.push_back(mapNums[target-nums[i]]);
                return vetRet;
            }
            mapNums[nums[i]] = i;    
        }
        return vetRet;
    }
};





