#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
public:
    string tree2str(TreeNode* t) {
        string str;
        if (t == NULL) {
            return str;
        }
        str = to_string(t->val);
        if (t->left == NULL && t->right == NULL) {
            return str;
        }

        if (t->right == NULL) {
            return str + "(" + tree2str(t->left) + ")";
        }
            
        return str + "(" + tree2str(t->left) + ")" + "(" + tree2str(t->right) + ")";
    }
};