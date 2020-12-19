#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给定一个非空字符串 s 和一个包含非空单词的列表 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。
// 说明：
// 拆分时可以重复使用字典中的单词。
// 你可以假设字典中没有重复的单词。


// v1 失败
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        
        int pos =0;
        while (1) {
            int temp = pos;
            for (int i = 0; i < wordDict.size(); i++) {
                if (wordDict[i] == s.substr(pos, wordDict[i].size())) {
                    pos += wordDict[i].size();
                    break;
                }
            }
            if (pos == s.size()) {
                return true;
            }
            if (pos == temp) {
                break;            
            }  
        }
        return false;
        
    }
};

// https://leetcode-cn.com/problems/word-break/solution/dong-tai-gui-hua-ji-yi-hua-hui-su-zhu-xing-jie-shi/
class Solution {
public:
    bool wordBreak(string& s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        for(int i = 0; i < s.size(); i++){
            if(!dp[i])
                continue;
            for(auto& word : wordDict)
                if(word.size() + i <= s.size() && s.substr(i, word.size()) == word)
                    dp[i+word.size()] = true;
                    
        }
        return dp[s.size()];
    }
};