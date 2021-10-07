#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {

        vector<vector<int> > vet_;

        vet_.push_back(p1);
        vet_.push_back(p2);
        vet_.push_back(p3);
        vet_.push_back(p4);

        std::sort(vet_.begin(), vet_.end(), [](const vector<int> & v1, const vector<int> & v2){
            return v1[0] < v2[0] ? true : (v1[0] == v2[0] ?  v1[1] < v2[1] : false);
        });
        long d01 = dist(vet_[0], vet_[1]);
        long d02 = dist(vet_[0], vet_[2]);
        long d13 = dist(vet_[1], vet_[3]);
        long d23 = dist(vet_[2], vet_[3]);

        long d03 = dist(vet_[0], vet_[3]);
        long d12 = dist(vet_[1], vet_[2]);

        return d03 == d12 && d01 == d02 && d02 == d13 && d13 == d23 && d01 != d03;

    }
        long dist(const vector<int>& a, const vector<int>& b) {
            return (b[1]-a[1])*(b[1]-a[1]) + (b[0]-a[0])*(b[0]-a[0]);
    }
};

int main() {
    vector<int > vet_;
    vet_.push_back(3);
    vet_.push_back(10);
    vet_.push_back(111);
    vet_.push_back(-1);
    vet_.push_back(4);
    std::sort(vet_.begin(), vet_.end(), [](int a, int b) {
        return a < b;
    });
    for(int i : vet_) {
        cout<< " " << i;
    }
    std::cout <<endl;
    return 0;
}