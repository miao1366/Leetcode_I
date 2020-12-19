#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：

// 每次转换只能改变一个字母。
// 转换过程中的中间单词必须是字典中的单词。
// 说明:

// 如果不存在这样的转换序列，返回 0。
// 所有单词具有相同的长度。
// 所有单词只由小写字母组成。
// 字典中不存在重复的单词。
// 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

// v1
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) {
            return 0;
        }
        dfs(wordList, 1, beginWord, endWord);
        return length ;
    }

    bool sameCharNums(const string &s1, string s2) {
        if(s1 == s2) return false;
        int nums = 0;
        for(int i = 0; i < s1.size(); i++) {
            size_t pos = s2.find(s1[i]);
            if (pos != string::npos) {
                ++nums;
                s2[pos] = '_';
            }
        }
        return nums == s2.size() - 1;
    }

    void dfs(vector<string> wordList, int nums, const string  begin, const string &end) {
        for(int i = 0; i < wordList.size(); i++) {
            if (wordList[i].size() == 0) continue;
            if (sameCharNums(begin, wordList[i]) && end == wordList[i]) {
                length = (length == 0) ? nums + 1: min(length, nums);
                return;
            } 
            if (sameCharNums(begin, wordList[i])) {
                string str = wordList[i];
                wordList[i] = "";
                dfs(wordList, ++nums, str, end);
            }

        }
    }
    int length;
};

// "hit" "cog"
// ["hot","dot","dog","lot","log","cog"]
// ["","dot","dog","lot","log","cog"]

int main(void) {
    // vector<string> vet{"hot", "dot", "dog", "lot", "log", "cog"};
    vector<string> vet{"a", "b", "c"};
    Solution sn;
    //cout<< sn.ladderLength("hit", "cog", vet) <<endl;
    cout<< sn.ladderLength("a", "c", vet) <<endl;
    return 0;
}