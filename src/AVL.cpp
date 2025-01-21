#include <iostream>
#include <queue>
#include <stack>
#include <regex>
#include <vector>
#include <algorithm>
#include <numeric>
#include <bits/hashtable_policy.h>

#include "./AVL1.h"

using namespace std;


AVL::AVL() {
    root = nullptr;
}


AVL::TreeNode* AVL::insertHelper(TreeNode* root,string name, string ID, int& count) {

    if (root == nullptr) {
        return new TreeNode(name, ID);
    }
    if (root->data == ID) {
        count++;
        return root;
    }

    if (stoi(ID) < stoi(root->data)) {
        root->left = insertHelper(root->left,name, ID,count);
    }
    else {
        root->right = insertHelper(root->right,name, ID,count);
    }
    root->height = 1 + max(root->left == nullptr? 0:root->left->height,root->right == nullptr? 0:root->right->height);
    root->balance_factor = (root->left == nullptr? 0:root->left->height) - (root->right == nullptr? 0:root->right->height);
    root = treeRotations(root);
    return root;
}

void AVL::insert(TreeNode* root,string name, string ID) {
    regex obj = regex("^[A-Za-z\\s]+$"); // [\\s]+$ more than one whitespace
    regex num = regex("[0-9]{8,8}");
    bool NameRegex = regex_match(name,obj);
    bool IDRegex = regex_match(ID,num);
    if (!NameRegex || !IDRegex) {
        cout << "unsuccessful" << endl;
        return;
    }
    int count = 0;
    TreeNode* curr = insertHelper(root,name,ID,count);
    if ((curr == nullptr) || (count != 0)) {
        cout << "unsuccessful" << endl;
    }
    else {
        this->root = curr;
        cout << "successful" << endl;
    }

}

void AVL::insertForTests(TreeNode* root,string name, string ID,vector<string>& v) {
    regex obj = regex("^[A-Za-z\\s]+$"); // [\\s]+$ more than one whitespace
    regex num = regex("[0-9]{8,8}");
    bool NameRegex = regex_match(name,obj);
    bool IDRegex = regex_match(ID,num);
    if (!NameRegex || !IDRegex) {
        v.push_back("unsuccessful");
        return;
    }
    int count = 0;
    TreeNode* curr = insertHelper(root,name,ID,count);
    if ((curr == nullptr) || (count != 0)) {
        v.push_back("unsuccessful");
    }
    else {
        this->root = curr;
        v.push_back("successful");
    }

}

AVL::TreeNode* AVL::removeIDHelper(TreeNode* root, string ID,int& count) {
    if (root == nullptr) {
        count++;
        return nullptr;
    }

    if (stoi(ID)  > stoi(root->data)) {
        root->right = removeIDHelper(root->right, ID,count);
    }
    else if (stoi(ID) < stoi(root->data)) {
        root->left = removeIDHelper(root->left, ID,count);
    }
    else {
        TreeNode* curr = root;
        if(curr->left == nullptr && curr->right == nullptr) {
            delete curr;
            return nullptr;
        }
        else if (curr->left == nullptr) {
            TreeNode* temp = root->right;
            delete curr;
            return temp;
        }
        else if (curr->right == nullptr) {
            TreeNode* temp = root->left;
            delete curr;
            return temp;
        }
        else {
            TreeNode* temp = successor(root);
            root->data = temp->data;
            root->name = temp->name;
            root->right = removeIDHelper(root->right, temp->data,count);
        }
    }
    updateHeights(root);
    updateBalanceFactor(root);
    root = treeRotations(root);
    return root;

}

void AVL::removeID(TreeNode* root, string ID) {
    int count = 0;
    root = removeIDHelper(root, ID,count);
    if ((root == nullptr) || (count != 0)) {
        cout << "unsuccessful" << endl;
    }
    else {
        cout << "successful" << endl;
    }
}

void AVL::removeIDForTests(TreeNode* root, string ID,vector<string>& v) {
    int count = 0;
    root = removeIDHelper(root, ID,count);
    if ((root == nullptr)||(count != 0)) {
        v.push_back("unsuccessful");
    }
    else {
        v.push_back("successful");
    }
}

AVL::TreeNode* AVL::removeInOrderHelper(TreeNode* root, string N,int& count) {
    vector<string> v;
    InOrderVector(root,v);
    if ((int)(v.size()) < stoi(N)+1) {
        root = nullptr;
    }
    else {
        root = removeIDHelper(root,v[stoi(N)],count);
    }
    return root;

}

void AVL::removeInOrder(TreeNode* root,string N) {
    int count = 0;
    root = removeInOrderHelper(root,N,count);
    if ((root == nullptr) || (count != 0)) {
        cout << "unsuccessful" << endl;
    }
    else {
        cout << "successful" << endl;
    }
}

void AVL::removeInOrderForTests(TreeNode* root,string N,vector<string>& v) {
    int count = 0;
    root = removeInOrderHelper(root,N,count);
    if ((root == nullptr) || (count != 0)) {
        v.push_back("unsuccessful");
    }
    else {
        v.push_back("successful");
    }
}


void AVL::searchID(TreeNode* root, string ID) {
    if (root == nullptr) {
        cout << "unsuccessful" << endl;
        return;
    }

    if (ID == root->data) {
        cout << root->name << endl;
        return;
    }

    if (ID > root->data) {
        searchID(root->right,ID);
    }
    else {
        searchID(root->left,ID);
    }

}

void AVL::searchIDForTests(TreeNode* root, string ID,vector<string>& v) {
    if (root == nullptr) {
        v.push_back("unsuccessful");
        return;
    }

    if (ID == root->data) {
        v.push_back(root->name);
        return;
    }

    if (ID > root->data) {
        searchIDForTests(root->right,ID,v);
    }
    else {
        searchIDForTests(root->left,ID,v);
    }

}

void AVL::searchNAMEHelper(TreeNode* root, string name, string& str) {

    if (root == nullptr) return;

    if (name == root->name) {
        str = str + root->data + "\n";

    }

    searchNAMEHelper(root->left,name,str);
    searchNAMEHelper(root->right,name,str);


}

void AVL::searchNAME(TreeNode* root, string name) {
    string MyString;
    searchNAMEHelper(root,name,MyString);
    if ((int)(MyString.size())==0) {
        cout << "unsuccessful" << endl;
    }
    else {
        cout << MyString << endl;
    }
}

void AVL::searchNAMEForTests(TreeNode* root, string name,vector<string>& v) {
    string MyString;
    searchNAMEHelper(root,name,MyString);
    if ((int)(MyString.size())==0) {
        v.push_back("unsuccessful");
    }
    else {
        v.push_back(MyString);
    }
}


// Got it from the slides
void AVL::printInOrderHelper(TreeNode* root,vector<string> &v) {
    string str;
    if (root == nullptr) return;

    printInOrderHelper(root->left,v);
    str = root->name + ", ";
    v.push_back(str);
    printInOrderHelper(root->right,v);
}

void AVL::printInOrder(TreeNode* root) {
    vector<string> v;
    string str;
    printInOrderHelper(root,v);
    if (v.empty()) {
        cout << "The tree is empty" << endl;
    }
    else {
        for (auto i:v) {
            str += i;
        }
        cout << str.substr(0,str.size()-2) << endl;
    }

}

void AVL::InOrderVector(TreeNode* root,vector<string>& v) {
    if (root == nullptr) {
        return;
    }
    InOrderVector(root->left,v);
    v.push_back(root->data);
    InOrderVector(root->right,v);
}

void AVL::InOrderVectorIntegers(TreeNode* root,vector<int>& v) {
    if (root == nullptr) {
        return;
    }
    InOrderVectorIntegers(root->left,v);
    v.push_back(stoi(root->data));
    InOrderVectorIntegers(root->right,v);
}


void AVL::printPreOrderHelper(TreeNode* root,vector<string>& v) {
    string str;
    if (root == nullptr) return;

    str = root->name + ", ";
    v.push_back(str);
    printPreOrderHelper(root->left,v);
    printPreOrderHelper(root->right,v);
}

void AVL::printPreOrder(TreeNode* root) {
    vector<string> v;
    string str;
    printPreOrderHelper(root,v);
    if (v.empty()) {
        cout << "The tree is empty" << endl;
    }
    else {
        for (auto i:v) {
            str += i;
        }
        cout << str.substr(0,str.size()-2) << endl;
    }

}

void AVL::printPostOrderHelper(TreeNode* root,vector<string>& v) {
    string str;
    if (root == nullptr) return;

    printPostOrderHelper(root->left,v);
    printPostOrderHelper(root->right,v);
    str = root->name + ", ";
    v.push_back(str);
}

void AVL::printPostOrder(TreeNode* root) {
    vector<string> v;
    string str;
    printPostOrderHelper(root,v);
    if (v.empty()) {
        cout << "The tree is empty" << endl;
    }
    else {
        for (auto i:v) {
            str += i;
        }
        cout << str.substr(0,str.size()-2) << endl;
    }

}


void AVL::printLevelCount(TreeNode* root) {
    if (root != nullptr) {
        cout << root->height << endl;
    }
    else {
        cout << 0 << endl;
    }

}

void AVL::updateHeights(TreeNode* root) {
    if (root == nullptr) return;

    updateHeights(root->left);
    updateHeights(root->right);
    root->height = 1 + max(root->left == nullptr? 0:root->left->height,root->right == nullptr? 0:root->right->height);

}

void AVL::updateBalanceFactor(TreeNode* root) {
    if (root == nullptr) return;

    updateBalanceFactor(root->left);
    updateBalanceFactor(root->right);
    root->balance_factor = (root->left == nullptr? 0:root->left->height) - (root->right == nullptr? 0:root->right->height);
}

AVL::TreeNode* AVL::successor(TreeNode* root) {
    // The smallest value of the right subtree
    if (root == nullptr || root->right == nullptr) {
        return nullptr;
    }
    TreeNode* curr = root->right;
    while (curr->left != nullptr) {
        curr = curr->left;
    }
    return curr;

}

AVL::TreeNode* AVL::treeRotations(TreeNode* root) {
    if (root->balance_factor == 2) { //Left heavy
        if ((root->left==nullptr? 0:root->left->balance_factor) == -1) {
            root = LRcase(root);
        }
        else {
            root = LLcase(root);
        }

    }
    else if (root->balance_factor == -2) { // Right heavy
        if ((root->right==nullptr? 0:root->right->balance_factor) == 1) {
            root = RLcase(root);
        }
        else {
            root = RRcase(root);
        }
    }
    return root;
}

AVL::TreeNode* AVL::RRcase(TreeNode* root) {
    TreeNode* grandchild = root->right->left;
    TreeNode* newparent = root->right;
    newparent->left = root;
    root->right = grandchild;
    //UPDATE HEIGHTS
    updateHeights(newparent);
    //UPDATE BALANCE FACTOR
    updateBalanceFactor(newparent);
    return newparent;

}

AVL::TreeNode* AVL::LLcase(TreeNode* root) {
    TreeNode* newparent = root->left;
    TreeNode* grandchild = root->left->right;
    newparent->right = root;
    root->left = grandchild;
    //UPDATE HEIGHTS
    updateHeights(newparent);
    //UPDATE BALANCE FACTOR
    updateBalanceFactor(newparent);
    return newparent;

}

AVL::TreeNode* AVL::LRcase(TreeNode* root) {
    root->left = RRcase(root->left);
    return LLcase(root);

}

AVL::TreeNode* AVL::RLcase(TreeNode* root) {
    root->right = LLcase(root->right);
    return RRcase(root);

}


void AVL::printLevelOrder(TreeNode* root,vector<string>& v) {
    queue<TreeNode*> q;
    if (root != nullptr) {
        v.push_back(root->name);
        q.push(root);
    }

    while (!q.empty()) {
        TreeNode* curr = q.front();
        q.pop();
        if (curr->left != nullptr) {
            v.push_back(curr->left->name);
            q.push(curr->left);
        }
        if (curr->right != nullptr) {
            v.push_back(curr->right->name);
            q.push(curr->right);
        }
    }
}


