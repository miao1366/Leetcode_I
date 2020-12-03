#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 给定一位研究者论文被引用次数的数组（被引用次数是非负整数）。编写一个方法，计算出研究者的 h 指数。
// h 指数的定义：h 代表“高引用次数”（high citations），一名科研人员的 h 指数是指他（她）的 （N 篇论文中）总共有 h 篇论文分别被引用了至少 h 次。且其余的 N - h 篇论文每篇被引用次数 不超过 h 次。
// 例如：某人的 h 指数是 20，这表示他已发表的论文中，被引用了至少 20 次的论文总共有 20 篇


//https://leetcode-cn.com/problems/h-index/comments/
class Solution {
public:
    int hIndex(vector<int>& citations) {
        std::sort(citations.begin(), citations.end());
        int ret = citations.size();
        for(int i=0;i<citations.size();i++){
            //比较小于则 h-1
            if(citations[i] < ret){
                ret--;
            }
        }
        return ret;
    }
};