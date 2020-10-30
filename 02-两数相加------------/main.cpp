#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

// 出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
// 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
// 您可以假设除了数字 0 之外，这两个数都不会以 0 开头

//    https://leetcode-cn.com/problems/add-two-numbers/solution/zui-jian-xie-fa-by-baal-3/
//    https://leetcode-cn.com/problems/add-two-numbers/solution/czhong-sheng-kong-jian-de-jie-fa-by-uycuqaawr5/
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


//v1 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       return addTwoNumbers(l1, l2, 0);

    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, int val) {
        if(l1 == NULL) return addTwoNumbers(NULL, l2, val);

    }
};