

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
  };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (nullptr == head || 0 == n) {
            return head;
        }
        ListNode * root = head;
        ListNode * removeList = nullptr;
        ListNode * prevList   = nullptr;
        while (root) {
            if (n == 0 || 0 == --n) {
                prevList = removeList;
                removeList =  removeList ? removeList ->next : head;
            }
            root = root ->next;
        }
        if (n ==0) {
            if (prevList) {
                prevList->next = removeList ? removeList->next : nullptr;
            } else {
                return removeList->next;
            }

        }
        return head;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    struct ListNode *p = head, *q = head;
    while(p){
        if(n < 0){ q = q -> next; }       
        n--;
        p = p -> next;
    }
    if(n == 0){ return head -> next; }
    q -> next = q -> next -> next;
    return head;
}

作者：newpp
链接：https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/solution/chao-jian-ji-shuang-zhi-zhen-fu-tu-jie-by-newpp/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。