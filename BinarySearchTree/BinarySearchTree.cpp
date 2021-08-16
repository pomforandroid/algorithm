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

};

int main()
{
	cout << "Hello CMake." << endl;
	return 0;
}
