#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

// 给你一个整数数组 arr，请你帮忙统计数组中每个数的出现次数。
// 如果每个数的出现次数都是独一无二的，就返回 true；否则返回 false。


// v1
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mapNum;
        int base = INT32_MIN;
        for (size_t i = 0; i < arr.size(); i++) {
            mapNum[arr[i]] = mapNum[arr[i]] + 1;
        }
        map<int, int>::iterator it = mapNum.begin();
        set<int> setNum;
        while(it != mapNum.end()) {
            if(setNum.count(it->second) != 0) {
                return false;
            } else {
                setNum.insert(it->second);
            }
            
            it++;
        }
        return mapNum.size() == setNum.size();
    }
};