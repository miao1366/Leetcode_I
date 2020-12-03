#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// 是利用递归与分治的技术将数据序列划分为越来越小的半子表，再对半子表排序，
// 最后再用递归方法将排好序的半子表合并成越来越大的有序序列

#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// 是利用递归与分治的技术将数据序列划分为越来越小的半子表，再对半子表排序，
// 最后再用递归方法将排好序的半子表合并成越来越大的有序序列

void popSort(int *array, int size) {
    int temp = 0;
    int flag = 0;
    for (int i = size -1; i > 0; i--) {
        flag = 1;
        for (int j = 0; j < i; j++) {
            if (array[j] < array[j + 1]) {
                temp = array[j];
                array[j] = array[j+1];
                array[j + 1] = temp;
                flag = 0;
            }
        }
        if (flag =1) {
            break;
        }
    }

}