// BinarySearchTree.cpp : Defines the entry point for the application.
//

#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <string>
#include "SequenceST.h"
#include "FileOps.h"

using namespace std;

template <typename Key, typename Value>
class BST {

private:
	struct Node
	{
		Key key;
		Value value;
		Node* left;
		Node* right;
		// struct 's constructor included in struct body
		Node(Key key, Value value) {
			this->key = key;
			this->value = value;
			this->left = this->right = NULL;
		}

	};
	
	Node* root;
	int count;
	
public:
	
	BST() {
		root = NULL;
		count = 0;
	}

	~BST() {
		destroy(root);
	}

	int size() {
		return count;
	}

	bool isEmpty() {
		return count == 0;
	}

	void insert(Key key, Value value) {
		root = insert(root, key, value);
	}

	bool contain(Key key) {
		return contain(root, key);
	}

	Value* search(Key key) {
		return search(root, key);
	}
	//preorder traversal
	void preOrder() {
		preOrder(root);
	}

	//in-order traversal
	void inOrder() {
		inOrder(root);
	}

	//post-order traversal
	void postOrder() {
		postOrder(root);
	}

private:

	void destroy(Node* node) {
		if (node != NULL) {
			destroy(node->left);
			destroy(node->right);
			delete node;
			count--;
		}
	}

	void postOrder(Node* node) {
		if (node != NULL) {
			preOrder(node->left);
			preOrder(node->right);
			cout << node->key << endl;
		}
	}

	void inOrder(Node* node) {
		if (node != NULL) {
			preOrder(node->left);
			cout << node->key << endl;
			preOrder(node->right);
		}
	}

	void preOrder(Node* node) {
		if (node != NULL) {
			cout << node->key << endl;
			preOrder(node->left);
			preOrder(node->right);
		}
	}




	Node* insert(Node* node, Key key, Value value) {
		if (node == NULL) {
			count++;
			return new Node(key, value);
		}
		if (node->key == key) {
			node->value = value;
		}
		else if (node->key > key) { // so key should be node 's left child
			node->left = insert(node->left, key, value);
		}
		else {
			node->right = insert(node->right, key, value);
		}
		return node;
	}

	// Returns whether the binary tree with "root" as the root node has a node whose key is "key" 
	bool contain(Node* node, Key key) {
		if (node == NULL)
			return false;

		if (node->key == key)
			return true;
		else if (key < node->key)
			return contain(node->left, key);
		else
			return contain(node->right, key);
	}
	// Returns the Value when the binary tree with "node" as the root node has a node whose key is "key" 
	Value* search(Node* node, Key key) {
		if (node == NULL)
			return NULL;

		if (node->key == key)
			return &(node->value);
		else if (key < node->key)
			return search(node->left, key);
		else
			return search(node->right, key);
	}

};

int main()
{
	cout << "Hello CMake." << endl;

	string filename = "D:\\wupengcong\\c++\\algorithm\\BinarySearchTree\\bible.txt";
	vector<string> words;
	if (FileOps::readFile(filename, words)) {
		cout << "There are totally " << words.size() << " words in " << filename << endl;
		cout << endl;

		//test BST 
		time_t startTime = clock();
		// Count the frequency of all words in the Bible
		BST<string, int> bst = BST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = bst.search(*iter);
			if (res == NULL)
				bst.insert(*iter, 1);
			else (* res)++;
		}

		if (bst.contain("god"))
			cout << "'god' : " << *bst.search("god") << endl;
		else 
			cout << "No word 'god' in " << filename << endl;

		time_t endTime = clock();

		cout << "BST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
		cout << endl;

		//test SST
		startTime = clock();
		SequenceST<string, int> sst = SequenceST<string, int>();
		for (vector<string>::iterator iter = words.begin(); iter != words.end(); iter++) {
			int* res = sst.search(*iter);
			if (res == NULL)
				sst.insert(*iter, 1);
			else
				(*res)++;
		}

		if (sst.contain("god"))
			cout << "'god' : " << *sst.search("god") << endl;
		else
			cout << "No word 'god' in " << filename << endl;

		endTime = clock();

		cout << "SST , time: " << double(endTime - startTime) / CLOCKS_PER_SEC << " s." << endl;
	}

	return 0;
}
