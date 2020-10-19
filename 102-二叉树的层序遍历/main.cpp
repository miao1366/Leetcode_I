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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vetRet;
        if (NULL == root) {
            return vetRet;
        }
        vector<TreeNode*> vetNode;
        vetNode.push_back(root);
        while(!vetNode.empty()) {
            vector<int> vetTmp;
            for(size_t i = 0; i < vetNode.size(); i++) {
                vetTmp.push_back(vetNode[i]->val);
            }
            vetRet.push_back(vetTmp);
            vector<TreeNode*> vetNodeTmp;
            for(size_t i = 0; i < vetNode.size(); i++) {
                if(vetNode[i]->left) {
                    vetNodeTmp.push_back(vetNode[i]->left);
                }
                if(vetNode[i]->right) {
                    vetNodeTmp.push_back(vetNode[i]->right);
                }
            }
            vetNode = vetNodeTmp;
        }
        return vetRet;
    }
};


// v2
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> vetRet;
        if (NULL == root) {
            return vetRet;
        }
        vector<TreeNode*> vetNode;
        vetNode.push_back(root);
        while(!vetNode.empty()) {
            vector<int> vetTmp;
            size_t  vetNodeSize = vetNode.size();
            for(size_t i = 0; i < vetNodeSize; i++) {
                TreeNode *tmp = vetNode.front();
                vetTmp.push_back(tmp->val);
                if(tmp->left) {
                    vetNode.push_back(tmp->left);
                }
                if(tmp->right) {
                    vetNode.push_back(tmp->right);
                }
                vetNode.erase(vetNode.begin());
            }
            vetRet.push_back(vetTmp);
        }
        return vetRet;
    }
};