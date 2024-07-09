#include <iostream>
#include <string>

using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *root;
    Node *insert(Node *node, int data)
    {
        cout << "Entering insert with data: " << data << endl;
        if (node == nullptr)
        {
            cout << "Inserting " << data << " at a new node" << endl;
            return new Node(data);
        }
        if (data < node->data)
        {
            cout << "Going left of " << node->data << endl;
            node->left = insert(node->left, data);
        }
        else if (data > node->data)
        {
            cout << "Going right of " << node->data << endl;
            node->right = insert(node->right, data);
        }
        cout << "Exiting insert with data: " << data << endl;
        return node;
    }
    void inorder(Node *node)
    {
        if (node == nullptr) return;
        cout << "Entering inorder with node data: " << node->data << endl;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
        cout << "Exiting inorder with node data: " << node->data << endl;
    }
    void postorder(Node *node)
    {
        if (node == nullptr) return;
        cout << "Entering postorder with node data: " << node->data << endl;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
        cout << "Exiting postorder with node data: " << node->data << endl;
    }
    void preorder(Node *node)
    {
        if (node == nullptr) return;
        cout << "Entering preorder with node data: " << node->data << endl;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
        cout << "Exiting preorder with node data: " << node->data << endl;
    }

public:
    BST() : root(nullptr) {}
    void insert(int data)
    {
        root = insert(root, data);
    }
    void inorderTraversal()
    {
        cout << "Inorder traversal: ";
        inorder(root);
        cout << endl;
    }
    void postorderTraversal()
    {
        cout << "Postorder traversal: ";
        postorder(root);
        cout << endl;
    }
    void preorderTraversal()
    {
        cout << "Preorder traversal: ";
        preorder(root);
        cout << endl;
    }
};

int main()
{
    BST bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(20);
    bst.insert(40);
    bst.insert(70);
    bst.insert(60);
    bst.insert(80);
    bst.inorderTraversal();
    bst.postorderTraversal();
    bst.preorderTraversal();
    return 0;
}