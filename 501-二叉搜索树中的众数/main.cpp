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

// v1 
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

// v2 
class Solution {
public:
    map<int, int> mapVal;
    vector<int> findMode(TreeNode* root) {
        fun(root);
    }
    int base = INT32_MIN;
    int count = 0;
    int maxcount = 0;
    vector<int>vetRet;

    void update(int val) {
        if (val == base) {
            count++;
        } else {
            base = val;
            count = 1;
        }
        if (count > maxcount) {
            maxcount = count;
            vetRet = vector<int> {val};
        } else if (count == maxcount) {
            vetRet.push_back(val);
        }
        
    }
        
    void fun(TreeNode* root) {
        if(NULL == root) {
            return;
        }
        fun(root->left);
        update(root->val);
        fun(root->right);
    }
};



