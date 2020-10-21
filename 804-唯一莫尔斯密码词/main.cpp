#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// //国际摩尔斯密码定义一种标准编码方式，将每个字母对应于一个由一系列点和短线组成的字符串， 
//比如: "a" 对应 ".-", "b" 对应 "-...", "c" 对应 "-.-.", 等等。
// 为了方便，所有26个英文字母对应摩尔斯密码表如下：
// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.",
//"---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]

char * arr[] = {
    ".-",
    "-...",
    "-.-.",
    "-..",
    ".",
    "..-.",
    "--.",
    "....",
    "..",
    ".---",
    "-.-",
    ".-..",
    "--",
    "-.",
    "---",
    ".--.",
    "--.-",
    ".-.",
    "...",
    "-",
    "..-",
    "...-",
    ".--",
    "-..-",
    "-.--",
    "--..",
};

class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        set<string> setStr;
        for(size_t i = 0; i < words.size(); i++) {
            string str;
            for(size_t j = 0; j < words[i].size(); j++) {
                str += arr[words[i][j]-'a'];
            }
            setStr.insert(str);
        }
        return setStr.size();
    }
};

