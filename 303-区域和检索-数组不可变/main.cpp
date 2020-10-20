#include <iostream>
#include <vector>
using namespace std;


//    v1
class NumArray {
public:
    NumArray(vector<int>& nums) {
        vetNums = nums;
    }
    
    int sumRange(int i, int j) {
        int sum =0;
        for(;i<vetNums.size() && i <= j; i++) {
            sum += vetNums[i];
        }
        return sum;
    }
   vector<int> vetNums;
};