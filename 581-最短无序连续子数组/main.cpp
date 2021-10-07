#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <limits.h>

using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (std::is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        vector<int> vet_(nums);
        std::sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size();
        while(nums[left] == vet_[left]) {
            ++left;
        }
        while(nums[right] == vet_[right]) {
            --right;
        }
        return right-left + 1;
    }
};

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if (std::is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        vector<int> vet_(nums);
        std::sort(nums.begin(),nums.end());
        int left = 0;
        int right = nums.size();
        while(nums[left] == vet_[left]) {
            ++left;
        }
        while(nums[right] == vet_[right]) {
            --right;
        }
        return right-left + 1;
    }
};


int main(void) {
    vector<int> vet_ = {2, 6, 4 ,8 , 10, 9, 15};
    Solution sl;
    cout << sl.findUnsortedSubarray(vet_) << endl;
    return 0;
}