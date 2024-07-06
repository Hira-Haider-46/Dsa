#include <iostream>
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
        if (node == nullptr) return new Node(data);
        if (data < node->data) node->left = insert(node->left, data);
        else if (data > node->data) node->right = insert(node->right, data);
        return node;
    }
    void inorder(Node *node)
    {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->data << " ";
        inorder(node->right);
    }
    void postorder(Node *node)
    {
        if (node == nullptr) return;
        postorder(node->left);
        postorder(node->right);
        cout << node->data << " ";
    }
    void preorder(Node *node)
    {
        if (node == nullptr) return;
        cout << node->data << " ";
        preorder(node->left);
        preorder(node->right);
    }
    Node *minValueNode(Node *node)
    {
        while (node && node->left != nullptr) node = node->left;
        return node;
    }
    Node *deleteNode(Node *root, int data)
    {
        if (root == nullptr) return root;
        if (data < root->data) root->left = deleteNode(root->left, data);
        else if (data > root->data) root->right = deleteNode(root->right, data);
        else
        {
            if (root->left == nullptr)
            {
                Node *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                Node *temp = root->left;
                delete root;
                return temp;
            }
            Node *temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        return root;
    }
    int Height(Node* node) 
    {
        if (node == nullptr) return 0;
        int leftHeight = Height(node->left);
        int rightHeight = Height(node->right);
        return max(leftHeight, rightHeight) + 1;
    }
    Node* search(Node* node, int data) 
    {
        if (node == nullptr || node->data == data) return node;
        if (data < node->data) return search(node->left, data);
        else return search(node->right, data);
    }
    Node* findMax(Node* node) 
    {
        while (node && node->right != nullptr) node = node->right;
        return node;
    }
    int diameter(Node* root) 
    {
        if (root == nullptr) return 0;
        int lh = Height(root->left);
        int rh = Height(root->right);
        int ld = diameter(root->left);
        int rd = diameter(root->right);
        return max(lh + rh + 1, max(ld, rd));
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
    void delNode(int data)
    {
        root = deleteNode(root, data);
    }
    void height()
    {
        cout << "Height of bst is " << Height(root) << endl;
    }
    void Search(int data)
    {
        if(search(root,data)) cout << data << " found in bst" << endl;
        else cout << data << " not found" << endl;
    }
    void Diameter()
    {
        cout << "Diameter of bst is: " << diameter(root) << endl;
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
    bst.delNode(80);
    bst.inorderTraversal();
    bst.height();
    // bst.postorderTraversal();
    // bst.preorderTraversal();
    return 0;
}