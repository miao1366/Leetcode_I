#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// 给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
// 你可以返回满足此条件的任何数组作为答案

// v1
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int> vetRet(A.size());
        size_t pos2=0;
        size_t pos1=A.size()-1;
        for(size_t i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0) {
                vetRet[pos2++] = A[i];
            } else {
                vetRet[pos1--] =A[i];
            }
        }
        return vetRet;
    }
};


// v2
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        int left=0,right=A.size()-1;
        while(left<right){
            if(A[left]%2==0) left++;
            else if(A[right]%2!=0) right--;
            else swap(A[left++],A[right--]); 
        }
        return A;
    }
};









