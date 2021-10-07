#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> map_;
        int max_count = 0;
        for (int num : nums) {
            map_[num] = map_[num] + 1;
            if (map_.count(num + 1)) {
                max_count = max_count < map_[num] + map_[num + 1] ? map_[num] + map_[num + 1] : max_count;
            }
            if (map_.count(num - 1)) {
                max_count = max_count < map_[num] + map_[num - 1] ? map_[num] + map_[num - 1] : max_count;
            }
        }
        return max_count;
    }
};