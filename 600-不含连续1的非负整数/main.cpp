#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

class Solution {
public:
    int findIntegers(int n) {
        if (0 == n) {
            return 1;
        }
        return findIntegers(n-1) + 1;
    }
    
};