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
};

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
