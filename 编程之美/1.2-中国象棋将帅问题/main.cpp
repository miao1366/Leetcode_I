#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

int main() {
    unsigned char index = 0x11;
    for(; index <= 9; i++) {
        for(int j = 1; j <= 9; j++) {
            if ((i%3) != (j%3)) {
                cout << "i: " << i << " j: " << j<< endl;
            }
        }
    }
    return 0;
}