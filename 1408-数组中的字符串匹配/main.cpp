#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

//给你一个字符串数组 words ，数组中的每个字符串都可以看作是一个单词。请你按 任意 顺序返回 words 中是其他单词的子字符串的所有单词。
//如果你可以删除 words[j] 最左侧和/或最右侧的若干字符得到 word[i] ，那么字符串 words[i] 就是 words[j] 的一个子字符串。

class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> vetRet;
        set<string> setStr;
        for(size_t i = 0; i < words.size(); i++) {
            for(size_t j = 0; j < words.size(); j++) {
                if (i == j) {
                    continue;
                }
                if(words[j].find(words[i]) != string::npos) {
                    setStr.insert(words[i]);
                }
            }
        }
        std::set<string>::iterator it;
        for(it = setStr.begin(); it != setStr.end(); it++) {
            vetRet.push_back(*it);
        }
        return vetRet;
    }
};


int main() {
    vector<string> vetStr;
    vetStr.push_back("mass");
    vetStr.push_back("as");
    vetStr.push_back("hero");
    vetStr.push_back("superhero");
    Solution su;
    vector<string> vet = su.stringMatching(vetStr);
    for(size_t i = 0; i < vet.size(); i++) {
        std::cout<< vet[i] << std::endl;
    }
    return 0;
}