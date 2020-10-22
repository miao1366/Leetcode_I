#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// 给定一个非负整数数组 A，返回一个数组，在该数组中， A 的所有偶数元素之后跟着所有奇数元素。
// 你可以返回满足此条件的任何数组作为答案

class Solution {
public:
    vector<string> commonChars(vector<string>& A) {
        std::vector<string> vetRet;
        for (size_t i = 0 ; i < A[0].size(); i++) {
            size_t count = 1;
            for (size_t j = 1 ; j < A.size(); j++) {
                if (A[j].find(A[0][i]) != string::npos) {
                    count++;
                } else {
                    break;
                }
                
            }
            if (count == A.size()) {
            for (size_t j = 1 ; j < A.size(); j++) {
                A[j][A[j].find(A[0][i])] = '0';
            }
            vetRet.push_back(string(1,A[0][i]));   
            } 
        }
        return vetRet;
    }
};