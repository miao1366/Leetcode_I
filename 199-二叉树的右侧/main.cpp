#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。


 //Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 

//  深度优先搜索 
//  https://leetcode-cn.com/problems/binary-tree-right-side-view/solution/jian-dan-bfsdfs-bi-xu-miao-dong-by-sweetiee/
class Solution {
public:
    vector<int> vetResult;
    vector<int> rightSideView(TreeNode* root) {
        dfs(root, 0);
        return vetResult;
    }
    void dfs(TreeNode * node , int depth) {
        if (nullptr == node) {
            return ;
        }
        if (depth == vetResult.size()) {
            vetResult.push_back(node->val);
        }
        ++depth;
        dfs(node->right, depth);
        dfs(node->left, depth);
    }
};


//    第一次就成功了
//    广度优先搜索
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> vetResult;
        vector<TreeNode *> vetNode;
        vector<TreeNode *> vetNodeTmp;
        if (nullptr != root) {
            vetNode.push_back(root);
        }

        while (! vetNode.empty()) {
            vetNodeTmp.clear();
            vetResult.push_back(vetNode[vetNode.size()-1]->val);
            for (int i = 0; i < vetNode.size(); ++i) {
                if (nullptr != vetNode[i]->left) {
                    vetNodeTmp.push_back(vetNode[i]->left);
                }
                if (nullptr != vetNode[i]->right) {
                    vetNodeTmp.push_back(vetNode[i]->right);
                }
            }
            vetNode = vetNodeTmp;
        }
        return vetResult;
    }
};