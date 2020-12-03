#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;

// 是利用递归与分治的技术将数据序列划分为越来越小的半子表，再对半子表排序，
// 最后再用递归方法将排好序的半子表合并成越来越大的有序序列