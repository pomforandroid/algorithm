// BinarySearchTree.cpp : Defines the entry point for the application.
//

#include "BinarySearchTree.h"

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
			this->left = this->value = null;
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
		// TODO 
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

	Node* insert(Node* node, Key key, Value value) {
		if (node == null) {
			count++;
			return new Node(key, value);
		}
		if (node->key == key) {
			node->value = value;
		}
		else if (node->key > key) { // so key should be node 's left child
			node->left = insert(node.left, key, value);
		}
		else {
			node->right = insert(node.right, key, value);
		}
		return node;
	}

	bool contain(Key key) {
		return contain(root, key);
	}

	Value* search(Key key) {
		return search(root, Key key);
	}

	// Returns whether the binary tree with "root" as the root node has a node whose key is "key" 
	bool contain(Node* root, Key key) {
		if (root == NULL)
			return false;
		
		if (root->key == key)
			return true;
		else if (key < root->key)
			return contain(root->left, key);
		else
			return contain(root->right, key);
	}
	// Returns the Value when the binary tree with "node" as the root node has a node whose key is "key" 
	Value* search(Node* node, Key key) {
		if (root == NULL)
			return NULL;

		if (root->key == key)
			return &(node->value);
		else if (key < root->key)
			return search(root->left, key);
		else
			return search(root->right, key);
	}

	
};

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
