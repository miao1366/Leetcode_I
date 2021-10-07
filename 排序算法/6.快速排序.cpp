#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;


// 分治法

// void quick_sort(int *p_val, int size) {
//     int base = *p_val, tmp = 0;
//     int *p_start = p_val, *p_end = p_val + size - 1;
//     if (size <= 1) {
//         return ;
//     }
//     while (p_start < p_end) {
//         //调整选定数字和另外一个数字
//         //之间的顺序
//         if (*p_start > *p_end) {
//             tmp = *p_start;
//             *p_start = *p_end;
//             *p_end = tmp;
//         }
//         //把非选定数字排除在外
//         if (*p_start == base) {
//             p_end--;
//         }
//         else {
//             p_start++;
//         }
//     }

//     quick_sort(p_val, p_start - p_val);
//     quick_sort(p_start + 1, size - (p_start - p_val) - 1);
// }

// //  快速排序的时间复杂度为 O(n(log n))
// //  快排是不稳定的算法


void quick_sort(int *array, size_t size) {
    if (NULL == array || size < 2) {
        return;
    }
    int *begin = array;
    int *end   = array + size - 1;
    int compare = *array;
    while (begin < end) {
        
    }
    
}

