#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 在一条环路上有 N 个加油站，其中第 i 个加油站有汽油 gas[i] 升。
// 你有一辆油箱容量无限的的汽车，从第 i 个加油站开往第 i+1 个加油站需要消耗汽油 cost[i] 升。你从其中的一个加油站出发，开始时油箱为空。
// 如果你可以绕环路行驶一周，则返回出发时加油站的编号，否则返回 -1。
// 说明: 
// 如果题目有解，该答案即为唯一答案。
// 输入数组均为非空数组，且长度相同。
// 输入数组中的元素均为非负数。

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int stationSize = gas.size();
        for (int i = 0; i < gas.size(); i++) {
            int oilHad = 0;
            for (int j = 0; j < gas.size(); j++) {
                oilHad += (gas[(i+j)%stationSize] - cost[(i+j)%stationSize]);
                if(oilHad < 0) {
                    break;
                }
            }
            if (oilHad >= 0) {
                return i;
            }
        }
        return -1;
    }
};
// 时间复杂度  n^2
// 空间复杂度  1


// https://leetcode-cn.com/problems/gas-station/solution/jia-you-zhan-by-leetcode/
// v2  
class Solution {
  public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int n = gas.size();

    int total_tank = 0;
    int curr_tank = 0;
    int starting_station = 0;
    for (int i = 0; i < n; ++i) {
      total_tank += gas[i] - cost[i];
      curr_tank += gas[i] - cost[i];
      // If one couldn't get here,
      if (curr_tank < 0) {
        // Pick up the next station as the starting one.
        starting_station = i + 1;
        // Start with an empty tank.
        curr_tank = 0;
      }
    }
    return total_tank >= 0 ? starting_station : -1;
  }
};
// 时间复杂度： O(N) ， 这是因为只有一个遍历了所有加油站一次的循环。
// 空间复杂度： O(1) ， 因为此算法只使用了常数个变量

// https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/
// https://leetcode-cn.com/problems/gas-station/solution/shi-yong-tu-de-si-xiang-fen-xi-gai-wen-ti-by-cyayc/

// 没看懂
class Solution {
  public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int len = gas.size();
    int spare = 0;
    int minSpare = INT32_MAX;
    int minIndex = 0;

    for (int i = 0; i < len; i++) {
        spare += gas[i] - cost[i];
        if (spare < minSpare) {
            minSpare = spare;
            minIndex = i;
        }
    }

    return spare < 0 ? -1 : (minIndex + 1) % len;
  }
};


int main(void) {
    vector<int> gas = {3, 3, 4};
    vector<int> cost = {3, 4, 4};
    Solution sn;
    cout << sn.canCompleteCircuit(gas, cost) << endl;
}