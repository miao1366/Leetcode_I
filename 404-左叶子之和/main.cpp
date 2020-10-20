#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// v1
class Solution {
public:
    int iSum = 0;
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        if (root->left && root->left->right == NULL && root->left->left == NULL) {
            iSum +=root->left->val;
        }
        sumOfLeftLeaves(root->left);
        sumOfLeftLeaves(root->right);
        return iSum;
    }
};


// v2
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        int iSum = 0;
        if (root == NULL) {
            return 0;
        }
        if (root->left && root->left->right == NULL && root->left->left == NULL) {
            iSum +=root->left->val;
        }
        return iSum + sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
    }
};