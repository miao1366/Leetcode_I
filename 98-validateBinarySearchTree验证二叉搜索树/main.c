#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>


/**
 * Definition for a binary tree node.
 * 
给定一个二叉树，判断其是否是一个有效的二叉搜索树。
假设一个二叉搜索树具有如下特征：
节点的左子树只包含小于当前节点的数。
节点的右子树只包含大于当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/validate-binary-search-tree
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



 struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
 };


// https://leetcode-cn.com/problems/validate-binary-search-tree/solution/zhong-xu-bian-li-qing-song-na-xia-bi-xu-miao-dong-/

// 01v 
// bool isValidBST(struct TreeNode* root){
//     if (!root) {
//         return true;
//     }
//     if (root->left) {
//         if (root->val <= root->left->val ) {
//             return false;
//         }
//     }
//     if (root->right) {
//         if (root->val >= root->right->val ) {
//             return false;
//         }
//     }
    
//     return (isValidBST(root->left) && isValidBST(root->right));
// }


// 02v 
int pre = INT_MIN;
bool isValidBST(struct TreeNode* root){
    if (!root) {
        return true;
    }
    // 访问左子树
    if (!isValidBST(root->left)) {
        return false;
    }
    // 访问当前节点：如果当前节点小于等于中序遍历的前一个节点，说明不满足BST，返回 false；否则继续遍历。
    if (root->val <= pre) {
        return false;
    }
    pre = root->val;
    // 访问右子树
    return isValidBST(root->right);
}

int main(void) {
    struct TreeNode node = {0, NULL, NULL};
    printf("%d\n" , isValidBST(&node));
}
// gcc main.c && ./a.out 