#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

/**给定二叉搜索树（BST）的根节点和一个值。 你需要在BST中找到节点值等于给定值的节点。 
 * 返回以该节点为根的子树。 如果节点不存在，则返回 NULL。*/

    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x) : val(x), left(NULL), right(NULL) {}
    };

//v1
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        TreeNode * tmp;
        if ((tmp = searchBST(root->left, val))) {
            return tmp;
        }
        if ((tmp = searchBST(root->right, val))) {
            return tmp;
        }
        return NULL;
    }
};

//v2
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL) {
            return NULL;
        }
        if (root->val == val) {
            return root;
        }
        return (root->val > val) ? searchBST(root->left, val) : searchBST(root->right, val);
    }
};

//v3
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(true){
            if(!root || root->val == val) return root;
            root = root->val > val ? root->left : root->right;
        }
    }
};
