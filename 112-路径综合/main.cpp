#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
#include <queue>
using namespace std;

// 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


// v1  深度优先搜索
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        return findValue(root, sum);
    }

    bool findValue(TreeNode* node, int num) {
        if(nullptr == node) {
            return false;
        }

        if (nullptr == node->left && nullptr == node->right) {
            return node->val == num;
        }
        
        return findValue(node->left, num-node->val) || findValue(node->right, num-node->val); 
        
    }

};

// 时间复杂度：O(N)，其中 N 是树的节点数。对每个节点访问一次。
// 空间复杂度：O(H)，其中 HH 是树的高度。空间复杂度主要取决于递归时栈空间的开销，最坏情况下，树呈现链状，
//      空间复杂度为 O(N)。平均情况下树的高度与节点数的对数正相关，空间复杂度为 



// 广度优先搜索
class Solution {
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == nullptr) {
            return false;
        }
        queue<TreeNode *> que_node;
        queue<int> que_val;
        que_node.push(root);
        que_val.push(root->val);
        while (!que_node.empty()) {
            TreeNode *now = que_node.front();
            int temp = que_val.front();
            que_node.pop();
            que_val.pop();
            if (now->left == nullptr && now->right == nullptr) {
                if (temp == sum) return true;
                continue;
            }
            if (now->left != nullptr) {
                que_node.push(now->left);
                que_val.push(now->left->val + temp);
            }
            if (now->right != nullptr) {
                que_node.push(now->right);
                que_val.push(now->right->val + temp);
            }
        }
        return false;
    }
};

// 时间复杂度：O(N)O(N)，其中 NN 是树的节点数。对每个节点访问一次。
// 空间复杂度：O(N)O(N)，其中 NN 是树的节点数。空间复杂度主要取决于队列的开销，队列中的元素个数不会超过树的节点数。

