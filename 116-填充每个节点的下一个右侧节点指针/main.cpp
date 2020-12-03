#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


// 要用常量空间
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        std::vector<Node *> vetNode;
        vetNode.push_back(root);
        while(true) {
            if(vetNode.size() == 0) {
                break;
            }
            for(int i = 1; i < vetNode.size(); i++) {
                vetNode[i - 1]->next = vetNode[i];
            }
            Node *pstNode = vetNode[0];
            vetNode.clear();
            while (pstNode) {
                if (pstNode->left != nullptr) {
                    vetNode.push_back(pstNode->left);
                }       
                if (pstNode->right != nullptr) {
                    vetNode.push_back(pstNode->right);
                }
                pstNode = pstNode->next;
            }
        }
        return root;
    }
};


class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) {
            return root;
        }
        dfs(root);
        return root;
    }

    void dfs(Node* root) {
        if(root->left==NULL&&root->right==NULL) {
            return;
        }
        Node* childLeft = root->left;
        Node* childRight = root->right;

        while(childLeft!=NULL) {
            childLeft->next = childRight;
            childLeft = childLeft->right;
            childRight = childRight->left;
        }
        dfs(root->left);
        dfs(root->right);
    }
};

class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL) {
            return root;
        }
        dfs(root);
        return root;
    }

    void dfs(Node* root) {
        if(root->left==NULL&&root->right==NULL) {
            return;
        }
        Node* childLeft = root->left;
        Node* childRight = root->right;

        while(childLeft!=NULL) {
            childLeft->next = childRight;
            childLeft = childLeft->right;
            childRight = childRight->left;
        }
        dfs(root->left);
        dfs(root->right);
    }
};


//  https://leetcode-cn.com/problems/populating-next-right-pointers-in-each-node/solution/bfshe-di-gui-zui-hou-liang-chong-ji-bai-liao-100-2/
//  深度优先遍历

class Solution {
public:
    Node* connect(Node* root) {
        dfs(root, nullptr);
        return root;
    }

    void dfs(Node* curr, Node* next) {
        if (curr == nullptr)
            return;
        curr->next = next;
        dfs(curr->left, curr->right);
        dfs(curr->right, curr->next == nullptr ? nullptr : curr->next->left);
    }
};

