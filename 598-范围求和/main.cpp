#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if (ops.size() == 0) {
            return m * n;
        }
        std::vector<int> vet_;
        vet_.resize(m*n);
        int max = -1;
        int maxCount = 0;
        for (size_t i = 0; i < ops.size(); i++) {
            int x = ops[i][0];
            int y = ops[i][1];
            for (int i = 0; i < x; i++) {
                for (int j = 0; j < y; j++) {
                    vet_[i * n + j ] = vet_[i * n + j ] + 1;
                    if (vet_[i * n + j ] > max) {
                        max = vet_[i * n + j ];
                        maxCount = 1;
                    } else if (vet_[i * n + j ] == max) {
                        ++maxCount;
                    } 
                }
            }
        }

        return maxCount;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for (size_t i = 0; i < ops.size(); i++) {
            m = m > ops[i][0] ? ops[i][0] : m;
            n = n > ops[i][1] ? ops[i][1] : n;
        }
        return m * n;
    }

}