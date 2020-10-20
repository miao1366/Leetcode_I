#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    map<int, int> mapVal;
    vector<int> findMode(TreeNode* root) {
        fun(root);
        vector<int>  vetRet;
        int max = INT32_MIN;
        map<int,int>::iterator it;
        for(it=mapVal.begin();it!=mapVal.end();++it) {
          if (it->second > max) {
              vetRet.clear();
              vetRet.push_back(it->first);
              max = it->second;
          } else if(it->second == max) {
              vetRet.push_back(it->first);
          }
        }
        return vetRet;
    }
     
    void fun(TreeNode* root) {
        if(NULL == root) {
            return;
        }
        if (mapVal.find(root->val) == mapVal.end()) {
            mapVal[root->val] = 1;
        } else {
            mapVal[root->val] += 1;
        }
        fun(root->left);
        fun(root->right);
    }



};