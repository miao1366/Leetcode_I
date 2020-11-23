#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;

// 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。


//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        findValue(root, sum, vector<int>());
        return m_ret;
    }
    void findValue(TreeNode* node, int num, vector<int> vet) {
        if(nullptr == node) {
            return ;
        }
        vet.push_back(node->val);
        if (nullptr == node->left && nullptr == node->right) {
            if (node->val == num) {
                m_ret.push_back(vet);
            }
        }
        
        findValue(node->left, num-node->val, vet) ;
        findValue(node->right, num-node->val,vet); 
        
    }
    vector<vector<int>> m_ret;
};