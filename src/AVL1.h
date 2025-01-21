#ifndef AVL_H
#define AVL_H
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

class AVL {
    struct TreeNode {
        string name, data;
        int height, balance_factor;
        TreeNode* left;
        TreeNode* right;

        TreeNode(const string &gatorname, string value) {
            name = gatorname;
            data = value;
            balance_factor = 0;
            height = 1;
            left = nullptr;
            right = nullptr;
        }
    };


public:
    TreeNode* root;
    AVL();
    void insert(TreeNode* root,string name, string ID);
    void insertForTests(TreeNode* root,string name, string ID,vector<string>& v);
    void printInOrderHelper(TreeNode* root,vector<string>& v);
    void printPreOrderHelper(TreeNode* root,vector<string>& v);
    void printPostOrderHelper(TreeNode* root,vector<string>& v);
    void printInOrder(TreeNode* root);
    void printPreOrder(TreeNode* root);
    void printPostOrder(TreeNode* root);
    void printLevelOrder(TreeNode* root,vector<string>& v);
    void printLevelCount(TreeNode* root);
    TreeNode* insertHelper(TreeNode* root,string name,string ID,int& count);
    TreeNode* removeIDHelper(TreeNode* root, string ID,int& count);
    void removeID(TreeNode* root,string ID);
    void removeIDForTests(TreeNode* root, string ID,vector<string>& v);
    TreeNode* removeInOrderHelper(TreeNode* root, string N,int& count);
    void removeInOrder(TreeNode* root,string N);
    void removeInOrderForTests(TreeNode* root, string N, vector<string>& v);
    TreeNode* successor(TreeNode* root);
    void searchID(TreeNode* root,string ID);
    void searchIDForTests(TreeNode* root,string ID,vector<string>& v);
    void searchNAMEHelper(TreeNode* root, string name,string& str);
    void searchNAME(TreeNode* root, string name);
    void searchNAMEForTests(TreeNode* root, string name,vector<string>& v);
    void InOrderVector(TreeNode* root,vector<string>& v);
    void InOrderVectorIntegers(TreeNode* root, vector<int>& v);
    void updateHeights(TreeNode*root);
    void updateBalanceFactor(TreeNode* root);
    TreeNode* RRcase(TreeNode* root);
    TreeNode* LLcase(TreeNode* root);
    TreeNode* LRcase(TreeNode* root);
    TreeNode* RLcase(TreeNode* root);
    TreeNode* treeRotations(TreeNode* root);
};



#endif //AVL_H



