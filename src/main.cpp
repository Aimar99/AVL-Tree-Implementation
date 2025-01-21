#include <iostream>
#include<regex>
#include "AVL1.h"
using namespace std;



int main() {
    AVL tree = AVL();
    string NumCommands, sentence, word, command, arg1, arg2;
    getline(cin, NumCommands);

    for (int i = 0; i < stoi(NumCommands); i++) {
        getline(cin, sentence);
        vector<string> words;
        stringstream ss(sentence);
        while (ss >> word) {
            words.push_back(word);
        }
        if (words.size() == 1) {
            command = words[0];
        }
        if (words.size() == 2) {
            command = words[0];
            arg1 = words[1];
        }
        if (words.size() == 3) {
            command = words[0];
            arg1 = words[1];
            arg2 = words[2];
        }
        if (command == "insert") {
            arg1 = arg1.substr(1, arg1.length() - 2);
            tree.insert(tree.root, arg1, arg2);
        }
        else if (command == "remove") {
            tree.removeID(tree.root, arg1);
        }
        else if (command == "search" && arg1[0] == '"'){
            arg1 = arg1.substr(1, arg1.length() - 2);
            tree.searchNAME(tree.root, arg1);
        }
        else if (command == "search" && arg1[0] != '"'){
            tree.searchID(tree.root, arg1);
        }
        else if (command == "printInorder") {
            tree.printInOrder(tree.root);
        }
        else if (command == "printPostorder") {
            tree.printPostOrder(tree.root);
        }
        else if (command == "printPreorder") {
            tree.printPreOrder(tree.root);
        }
        else if (command == "printLevelCount") {
            tree.printLevelCount(tree.root);
        }
        else if (command == "removeInorder") {
            tree.removeInOrder(tree.root,arg1);
        }
        else {
            cout << "unsuccessful" << endl;
        }

    }

}



