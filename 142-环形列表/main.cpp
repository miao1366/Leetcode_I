#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给定一个链表，返回链表开始入环的第一个节点。 如果链表无环，则返回 null。
// 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。
// 注意，pos 仅仅是用于标识环的情况，并不会作为参数传递到函数中。


// 进阶：
// 你是否可以使用 O(1) 空间解决此题？

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// v1 
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode *> nodeSet;
        ListNode *pstNodehead = head;
        while(pstNodehead) {
            if(nodeSet.count(pstNodehead) == 1) {
                return pstNodehead;
            }
            nodeSet.insert(pstNodehead);
            pstNodehead = pstNodehead->next;
        }
        
        return nullptr;
    }

};

// 时间复杂度：O(N)O(N)
// 空间复杂度：O(N)O(N)
// v2


class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *pstNodeCurrent = head;
        while(pstNodeCurrent) {
            ListNode *tempNext = pstNodeCurrent->next;
            ListNode *pstTempHead = head;
            while(pstTempHead != pstNodeCurrent) {
                if (tempNext == pstTempHead) {
                    return tempNext;
                }
                pstTempHead = pstTempHead->next; 
            }
            pstNodeCurrent = pstNodeCurrent->next;
        }
        
        return nullptr;
    }

};

// v3
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast != nullptr) {
            slow = slow->next;
            if (fast->next == nullptr) {
                return nullptr;
            }
            fast = fast->next->next;
            if (fast == slow) {
                ListNode *ptr = head;
                while (ptr != slow) {
                    ptr = ptr->next;
                    slow = slow->next;
                }
                return ptr;
            }
        }
        return nullptr;
    }
};
// 时间复杂度：O(N)O(N)，其中 NN 为链表中节点的数目。在最初判断快慢指针是否相遇时，
// slow 指针走过的距离不会超过链表的总长度；随后寻找入环点时，走过的距离也不会超过链表的总长度。因此，总的执行时间为 O(N)+O(N) = O(N)


// 空间复杂度：O(1)O(1)

int main(void) {
    ListNode node(2);
    Solution s;
    cout << s.detectCycle(&node) <<endl;
    return 0;
}









