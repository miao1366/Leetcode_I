#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

// 你写出一个秘密数字，并请朋友猜这个数字是多少。
// 朋友每猜测一次，你就会给他一个提示，告诉他的猜测数字中有多少位属于数字和确切位置都猜对了（称为“Bulls”, 公牛），有多少位属于数字猜对了但是位置不对（称为“Cows”, 奶牛）。
// 朋友根据提示继续猜，直到猜出秘密数字。
// 请写出一个根据秘密数字和朋友的猜测数返回提示的函数，返回字符串的格式为 xAyB ，x 和 y 都是数字，A 表示公牛，用 B 表示奶牛。

// xA 表示有 x 位数字出现在秘密数字中，且位置都与秘密数字一致。
// yB 表示有 y 位数字出现在秘密数字中，但位置与秘密数字不一致。
// 请注意秘密数字和朋友的猜测数都可能含有重复数字，每位数字只能统计一次。


// v1  xx
class Solution {
public:
    string getHint(string secret, string guess) {
        string strRet("AABB");
        std::vector<bool> vetChecked(secret.size(), false);
        int bulls = 0;
        int cows = 0;
        for(size_t i = 0; i < guess.size(); i++) {
            if(guess[i] == secret[i]) {
                vetChecked[i] = true;
                ++bulls;
            }
        }
        for(size_t i = 0; i < guess.size(); i++) {
            for (size_t j = 0; j < secret.size(); ++j) {
                if(guess[i] == secret[j] && !vetChecked[j]) {
                    vetChecked[j] = true;
                    ++cows;
                }
            }
            
        }
        strRet[0] = 48 + bulls;
        strRet[2] = 48 + cows;
        return strRet;
    }
};

//  https://leetcode-cn.com/problems/bulls-and-cows/solution/java-yi-ci-bian-li-by-ge-ge-da-s/  具有参考价值