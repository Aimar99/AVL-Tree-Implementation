/*
#include <algorithm>
#include <catch2/catch_test_macros.hpp>
#include "AVL1.h"
#include "main.cpp"
#include <iostream>



using namespace std;


// the provided test from the template is below.
TEST_CASE("Incorrect commands AVL","[flag]") {
	vector<string> v;
	AVL tree1 = AVL();
	tree1.insert(tree1.root,"Aimar Murua","98185284");
	// Inserting an incorrect node (Name consisting of numbers)
	tree1.insertForTests(tree1.root,"A11","98185284",v);
	// Inserting a node whose ID already exists in the tree
	tree1.insertForTests(tree1.root,"Naia Murua","98185284",v);
	// Inserting an incorrect node (ID length != 8)
	tree1.insertForTests(tree1.root,"Aimar Murua Poza","9818528",v);
	// Inserting an incorrect node (ID with a number)
	tree1.insertForTests(tree1.root,"Aimar Murua Poza","98A12344",v);
	// Searching for a name that doesn't exist inside the tree
	tree1.searchNAMEForTests(tree1.root,"Aimar Murua Poza",v);
	// Searching for an incorrect ID (length != 8)
	tree1.searchIDForTests(tree1.root,"9818528",v);

	REQUIRE(v[0] == "unsuccessful");
	REQUIRE(v[1] == "unsuccessful");
	REQUIRE(v[2] == "unsuccessful");
	REQUIRE(v[3] == "unsuccessful");
	REQUIRE(v[4] == "unsuccessful");
	REQUIRE(v[5] == "unsuccessful");



}

TEST_CASE("Edge cases AVL","[flag]") {
	vector<string> v1,v2,v3;
	AVL tree = AVL();
	// Deletion from an empty tree
	tree.removeIDForTests(tree.root,"111",v1);
	REQUIRE(v1[0] == "unsuccessful");
	tree.insert(tree.root,"Aimar","98185284");
	// Deleting a node that doesn't exist
	tree.removeInOrderForTests(tree.root,"111",v2);
	REQUIRE(v2[0] == "unsuccessful");
	// Searching for an ID that doesn't exist
	tree.searchIDForTests(tree.root,"111",v3);
	REQUIRE(v3[0] == "unsuccessful");
}

TEST_CASE("Rotations Tests AVL","[flag]") {
	vector<string> v1,v2,v3,v4;

	// Right Right case
	AVL tree1 = AVL();
	tree1.insert(tree1.root,"Naia","12345678");
	tree1.insert(tree1.root,"Aitor","23456789");
	tree1.insert(tree1.root,"Itziar","34567890");
	tree1.root = tree1.treeRotations(tree1.root);
	tree1.printLevelOrder(tree1.root,v1);
	REQUIRE(v1[0] == "Aitor");
	REQUIRE(v1[1] == "Naia");
	REQUIRE(v1[2] == "Itziar");

	// Left Left case
	AVL tree2 = AVL();
	tree2.insert(tree2.root,"Itziar","34567890");
	tree2.insert(tree2.root,"Aitor","23456789");
	tree2.insert(tree2.root,"Naia","12345678");
	tree2.root = tree2.treeRotations(tree2.root);
	tree2.printLevelOrder(tree2.root,v2);
	REQUIRE(v2[0] == "Aitor");
	REQUIRE(v2[1] == "Naia");
	REQUIRE(v2[2] == "Itziar");

	// Right Left case
	AVL tree3 = AVL();
	tree3.insert(tree3.root,"Naia","12345678");
	tree3.insert(tree3.root,"Itziar","34567890");
	tree3.insert(tree3.root,"Aitor","23456789");
	tree3.root = tree3.treeRotations(tree2.root);
	tree3.printLevelOrder(tree3.root,v3);
	REQUIRE(v3[0] == "Aitor");
	REQUIRE(v3[1] == "Naia");
	REQUIRE(v3[2] == "Itziar");

	// Left Right case
	AVL tree4 = AVL();
	tree4.insert(tree4.root,"Itziar","34567890");
	tree4.insert(tree4.root,"Naia","12345678");
	tree4.insert(tree4.root,"Aitor","23456789");
	tree4.root = tree4.treeRotations(tree2.root);
	tree4.printLevelOrder(tree4.root,v4);
	REQUIRE(v4[0] == "Aitor");
	REQUIRE(v4[1] == "Naia");
	REQUIRE(v4[2] == "Itziar");


}


TEST_CASE("Deletion cases AVL","[flag]") {
	vector <string> v1,v2,v3;
	// Deletion of a leaf
	AVL tree1 = AVL();
	tree1.insert(tree1.root,"Aitor","23456789");
	tree1.insert(tree1.root,"Naia","12345678");
	tree1.insert(tree1.root,"Itziar","34567890");
	tree1.insert(tree1.root,"Aimar","01234567");
	tree1.insert(tree1.root,"Esti","34455678");
	tree1.insert(tree1.root,"Xabi","23356789");
	tree1.removeID(tree1.root,"01234567");
	tree1.printLevelOrder(tree1.root,v1);
	REQUIRE(v1[0] == "Aitor");
	REQUIRE(v1[1] == "Naia");
	REQUIRE(v1[2] == "Itziar");
	REQUIRE(v1[3] == "Xabi");
	REQUIRE(v1[4] == "Esti");

	// Deletion of a node with only one child
	AVL tree2 = AVL();
	tree2.insert(tree2.root,"Aitor","23456789");
	tree2.insert(tree2.root,"Naia","12345678");
	tree2.insert(tree2.root,"Itziar","34567890");
	tree2.insert(tree2.root,"Aimar","01234567");
	tree2.insert(tree2.root,"Esti","34455678");
	tree2.insert(tree2.root,"Xabi","23356789");
	tree2.removeID(tree2.root,"34567890");
	tree2.printLevelOrder(tree2.root,v2);
	REQUIRE(v2[0] == "Aitor");
	REQUIRE(v2[1] == "Naia");
	REQUIRE(v2[2] == "Esti");
	REQUIRE(v2[3] == "Aimar");
	REQUIRE(v2[4] == "Xabi");


	// Deletion of a node with two children
	AVL tree3 = AVL();
	tree3.insert(tree3.root,"Aitor","23456789");
	tree3.insert(tree3.root,"Naia","12345678");
	tree3.insert(tree3.root,"Itziar","34567890");
	tree3.insert(tree3.root,"Aimar","01234567");
	tree3.insert(tree3.root,"Esti","34455678");
	tree3.insert(tree3.root,"Xabi","23356789");
	tree3.removeID(tree3.root,"23456789");
	tree3.printLevelOrder(tree3.root,v3);
	REQUIRE(v3[0] == "Esti");
	REQUIRE(v3[1] == "Naia");
	REQUIRE(v3[2] == "Itziar");
	REQUIRE(v3[3] == "Aimar");
	REQUIRE(v3[4] == "Xabi");

}

TEST_CASE("Insertion of 100 nodes","[flag]") {
	AVL tree = AVL();
	vector<int> expectedOutput, actualOutput;
	int num = 0;
	for (int i = 0; i < 1000; i++) {
		int randomInput = rand();
		randomInput = (randomInput + 10000000) % 99999999;
		if ((count(expectedOutput.begin(), expectedOutput.end(), randomInput) == 0) && (num < 100)) {
			expectedOutput.push_back(randomInput);
			tree.insert(tree.root,"Aimar",to_string(randomInput));
			num++;
		}
	}

	for (int i = 0; i < 10; i++) {
		int index = rand() % expectedOutput.size();
		tree.removeID(tree.root,to_string(expectedOutput[index]));
		expectedOutput.erase(expectedOutput.begin() + index);
	}

	tree.InOrderVectorIntegers(tree.root,actualOutput);
	REQUIRE(actualOutput.size() == expectedOutput.size());
	sort(expectedOutput.begin(), expectedOutput.end());
	REQUIRE(actualOutput == expectedOutput);

}
*/