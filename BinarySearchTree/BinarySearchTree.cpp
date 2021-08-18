// BinarySearchTree.cpp : Defines the entry point for the application.
//

#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <string>
#include "SequenceST.h"
#include "FileOps.h"
#include <queue>

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

		Node(Node* node) {
			this->key = node->key;
			this->value = node->value;
			this->left = node->left;
			this->right = node->right;
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

	void levelOrder() {
		queue<Node> q = new queue<Node>();
		q.push(root);
			
		while (!q.empty()) {
			Node* front = q.front();
			q.pop();
			cout << node->key << endl;
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
	}

	Key minimum() {
		assert(count != 0);
		Node* minNode = minimum(root);
		return minNode->key;
	}

	Node* maximum() {
		assert(count != 0);
		Node* maxNode = maximum(root);
		return maxNode->key;
	}

	void removeMin() {
		if(root)
			root = removeMin(root);
	}

	void removeMax() {
		if(root)
			root = removeMax(root);
	}

	void remove(Key key) {
		root = remove(root, key);
	}

private:

	Node* remove(Node* node, Key key) {
		if (node == NULL)
			return NULL;

		if (key < node->key) {
			node->left = remove(node->left, key); //"node->left= " it means it link the returns node;,it is important
			return node;
		}
		else if (key > node->key) {
			node->right = remove(node->right, key);
			return node;
		}
		else { //key == node->key
			
			if (node->left == NULL) {
				Node* rightNode = node->right;
				delete node;
				count--;
				return rightNode;
			}

			if (node->right == NULL) {
				Node* leftNode = node->left;
				delete node;
				count--;
				return leftNode;
			}

			
			Node* successor = new Node(suminimum(node.right));
			count++;
			successor->right = removeMin(node->right);;
			successor->left = node->left;
			delete node;
			count--;
			return successor;
		}
	}


	Node* removeMin(Node* node) {
		if (node->left == NULL) {
			Node* rightNode = node->right;
			delete node;
			count--;
			return rightNode;
		}
		node->left = removeMin(node->left);//splicing
		return node;
	}

	Node* removeMax(Node* node) {
		if (node->right == NULL) {
			Node* leftNode = node->left;
			delete node;
			count--;
			return leftNode;
		}
		node->right = removeMax(node->right);
		return node;
	}

	//return the node with max value in BST whose root node is "node"
	Node* maximum(Node* node) {
		if (node->right == NULL) {
			return node;
		}
		return maximum(node->right);
	}
	//return the node with min value in BST whose root node is "node"
	Node* minimum(Node* node) {
		if (node->left == NULL) {
			return node;
		}
		return minimum(node->left);
	}

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
