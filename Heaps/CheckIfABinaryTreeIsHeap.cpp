#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
	Node(int val) : key(val), left(nullptr), right(nullptr) {} 
};

int countNodes(Node *root)
{
	if (root == NULL) return (0);
	return (1 + countNodes(root->left) + countNodes(root->right));
}

bool isCompleteUtil(Node *root, int index, int number_nodes)
{
	if (root == NULL) return (true);
	// If index assigned to current node is more than number of nodes in tree, then tree is not complete
	if (index >= number_nodes) return (false);
	return (isCompleteUtil(root->left, 2 * index + 1, number_nodes) && isCompleteUtil(root->right, 2 * index + 2, number_nodes));
}

bool isHeapUtil(Node *root)
{
	if (root->left == NULL && root->right == NULL) return (true);
	// node will be in second last level
	if (root->right == NULL) return (root->key >= root->left->key); // check heap property at Node No recursive call, because no need to check last level
	else
	{
		// Check heap property at Node and Recursive check heap property at left and right subtree
		if (root->key >= root->left->key && root->key >= root->right->key) return ((isHeapUtil(root->left)) && (isHeapUtil(root->right)));
		else return (false);
	}
}

bool isHeap(Node *root)
{
	int node_count = countNodes(root);
	int index = 0;
	if (isCompleteUtil(root, index, node_count) && isHeapUtil(root)) return true;
	return false;
}

int main()
{
	Node *root = new Node(10);
    root->left = new Node(9);
    root->right = new Node(8);
    root->left->left = new Node(7);
    root->left->right = new Node(6);
    root->right->left = new Node(5);
    root->right->right = new Node(4);
    root->left->left->left = new Node(3);
    root->left->left->right = new Node(2);
    root->left->right->left = new Node(1);
	if (isHeap(root)) cout << "Given binary tree is a Heap\n";
	else cout << "Given binary tree is not a Heap\n";
	return 0;
}