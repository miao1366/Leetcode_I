#include <iostream>
using namespace std;

struct ListNode {
    int val_;
    struct ListNode *next_;
    ListNode(int val) : val_(val), next_(NULL) {}
    ListNode(ListNode *next, int val): next_(next), val_(val) {}
};

void print_list(ListNode *pHead) {
    while (pHead) {
        std::cout << pHead->val_ << " ";
        pHead = pHead ->next_;
    }
    std::cout << std::endl;
}

ListNode* ReverseList(ListNode* pHead) {
    if (NULL == pHead) return pHead;
    ListNode *pRoot = pHead;
    ListNode *pPrev = NULL;
    ListNode *pTemp = NULL;
    while(pRoot) {
        pTemp = pRoot->next_;
        pRoot->next_ = pPrev;
        pPrev = pRoot;
        pRoot = pTemp;
    }
    print_list(pPrev);
    return NULL;
}

int main() {
    ListNode node1(1);
    ListNode node2(&node1, 2);
    ListNode node3(&node2, 3);
    ListNode node4(&node3, 4);
    ListNode node5(&node4, 5);
    ListNode node6(&node5, 6);

    print_list(&node6);
    ReverseList(&node6);
    return 0;
}
