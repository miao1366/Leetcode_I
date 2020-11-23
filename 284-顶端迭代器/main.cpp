#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class PeekingIterator : public Iterator {
 int cur;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        if (Iterator::hasNext()) cur = Iterator::next();
        else cur = -1;
    }
    
    int peek() {
        return cur;
    }

    int next() {
        int ans = cur;
        if (Iterator::hasNext()) cur = Iterator::next();
        else cur = -1;
        return ans;
    }

    bool hasNext() const {
        return cur != -1;
    }
};