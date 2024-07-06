#include "node.h"

template <class T>
class AVLTree
{
private:
    Node *root;
    Node *insert(Node *node, T key);
    Node *remove(Node *node, T key);
    Node *search(Node *node, T key);
    void inorderTraversal(Node *node);
    void preorderTraversal(Node *node);
    void postorderTraversal(Node *node);
    int height(Node *node);
    int getBalance(Node *node);
    Node *rotateRight(Node *y);
    Node *rotateLeft(Node *x);
    Node *minValueNode(Node *node);
    Node *maxValueNode(Node *node);
    Node *findSuccessor(Node *node);
    Node *findPredecessor(Node *node);
    int diameter(Node *node, T *height);
    void destroy(Node *node);

public:
    AVLTree() : root(nullptr) {}
    void insert(T key);
    void remove(T key);
    bool search(T key);
    void inorderTraversal();
    void preorderTraversal();
    void postorderTraversal();
    int height();
    int diameter();
    T findMin();
    T findMax();
    T findSuccessor(T key);
    T findPredecessor(T key);
    ~AVLTree()
    {
        destroy(root);
    }
};

template <class T>
Node *AVLTree<T>::insert(Node *node, T key)
{
    if (node == nullptr) return new Node(key);
    if (key < node->key) node->left = insert(node->left, key);
    else if (key > node->key) node->right = insert(node->right, key);
    else return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key) return rotateRight(node); // Left Left Case
    if (balance < -1 && key > node->right->key) return rotateLeft(node); // Right Right Case
    if (balance > 1 && key > node->left->key) // Left Right Case
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && key < node->right->key) // Right Left Case
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template <class T>
Node *AVLTree<T>::remove(Node *node, T key)
{
    if (node == nullptr) return node;
    if (key < node->key) node->left = remove(node->left, key);
    else if (key > node->key) node->right = remove(node->right, key);
    else
    {
        if (node->left == nullptr || node->right == nullptr)
        {
            Node *temp = node->left ? node->left : node->right; // ternary operator condition ? yes : no
            if (temp == nullptr)
            {
                temp = node;
                node = nullptr;
            }
            else *node = *temp;
            delete temp;
        }
        else
        {
            Node *temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = remove(node->right, temp->key);
        }
    }
    if (node == nullptr) return node;
    node->height = 1 + max(height(node->left), height(node->right));
    int balance = getBalance(node);
    if (balance > 1 && getBalance(node->left) >= 0) return rotateRight(node);  // Left Left Case
    if (balance > 1 && getBalance(node->left) < 0) // Left Right Case
    {
        node->left = rotateLeft(node->left);
        return rotateRight(node);
    }
    if (balance < -1 && getBalance(node->right) <= 0) return rotateLeft(node); // Right Right Case
    if (balance < -1 && getBalance(node->right) > 0) // Right Left Case
    {
        node->right = rotateRight(node->right);
        return rotateLeft(node);
    }
    return node;
}

template <class T>
Node *AVLTree<T>::search(Node *node, T key)
{
    if ((node == nullptr) || (node->key == key)) return node;
    if (key < node->key) return search(node->left, key);
    else return search(node->right, key);
}

template <class T>
void AVLTree<T>::inorderTraversal(Node *node)
{
    if (node != nullptr)
    {
        inorderTraversal(node->left);
        cout << node->key << " ";
        inorderTraversal(node->right);
    }
}

template <class T>
void AVLTree<T>::preorderTraversal(Node *node)
{
    if (node != nullptr)
    {
        cout << node->key << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->right);
    }
}

template <class T>
void AVLTree<T>::postorderTraversal(Node *node)
{
    if (node != nullptr)
    {
        postorderTraversal(node->left);
        postorderTraversal(node->right);
        cout << node->key << " ";
    }
}

template <class T>
int AVLTree<T>::height(Node *node)
{
    if (node == nullptr) return 0;
    return node->height;
}

template <class T>
int AVLTree<T>::getBalance(Node *node)
{
    if (node == nullptr) return 0;
    return height(node->left) - height(node->right);
}

template <class T>
Node *AVLTree<T>::rotateRight(Node *y)
{
    Node *x = y->left, *T2 = x->right;
    x->right = y;
    y->left = T2;
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
    return x;
}

template <class T>
Node *AVLTree<T>::rotateLeft(Node *x)
{
    Node *y = x->right, *T2 = y->left;
    y->left = x;
    x->right = T2;
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
    return y;
}

template <class T>
Node *AVLTree<T>::minValueNode(Node *node)
{
    Node *current = node;
    while (current->left) current = current->left;
    return current;
}

template <class T>
Node *AVLTree<T>::maxValueNode(Node *node)
{
    Node *current = node;
    while (current->right) current = current->right;
    return current;
}

template <class T>
Node *AVLTree<T>::findSuccessor(Node *node)
{
    if (node->right != nullptr) return minValueNode(node->right);
    Node *successor = nullptr, *ancestor = root;
    while (ancestor != node)
    {
        if (node->key < ancestor->key)
        {
            successor = ancestor;
            ancestor = ancestor->left;
        }
        else ancestor = ancestor->right;
    }
    return successor;
}

template <class T>
Node *AVLTree<T>::findPredecessor(Node *node)
{
    if (node->left) return maxValueNode(node->left);
    Node *predecessor = nullptr, *ancestor = root;
    while (ancestor != node)
    {
        if (node->key > ancestor->key)
        {
            predecessor = ancestor;
            ancestor = ancestor->right;
        }
        else ancestor = ancestor->left;
    }
    return predecessor;
}

template <class T>
int AVLTree<T>::diameter(Node *node, T *height)
{
    int leftHeight = 0, rightHeight = 0, leftDiameter = 0, rightDiameter = 0;
    if (node == nullptr)
    {
        *height = 0;
        return 0;
    }
    leftDiameter = diameter(node->left, &leftHeight);
    rightDiameter = diameter(node->right, &rightHeight);
    *height = max(leftHeight, rightHeight) + 1;
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
}

template <class T>
void AVLTree<T>::destroy(Node *node)
{
    if (node != nullptr)
    {
        destroy(node->left);
        destroy(node->right);
        delete node;
    }
}

template <class T>
void AVLTree<T>::insert(T key)
{
    root = insert(root, key);
}

template <class T>
void AVLTree<T>::remove(T key)
{
    root = remove(root, key);
}

template <class T>
bool AVLTree<T>::search(T key)
{
    return search(root, key) != nullptr;
}

template <class T>
void AVLTree<T>::inorderTraversal()
{
    inorderTraversal(root);
    cout << endl;
}

template <class T>
void AVLTree<T>::preorderTraversal()
{
    preorderTraversal(root);
    cout << endl;
}

template <class T>
void AVLTree<T>::postorderTraversal()
{
    postorderTraversal(root);
    cout << endl;
}

template <class T>
int AVLTree<T>::height()
{
    return height(root);
}

template <class T>
int AVLTree<T>::diameter()
{
    int heightVal = 0;
    return diameter(root, &heightVal);
}

template <class T>
T AVLTree<T>::findMin()
{
    Node *node = minValueNode(root);
    return node ? node->key : -1;
}

template <class T>
T AVLTree<T>::findMax()
{
    Node *node = maxValueNode(root);
    return node ? node->key : -1;
}

template <class T>
T AVLTree<T>::findSuccessor(T key)
{
    Node *node = search(root, key);
    if (node == nullptr) return -1;
    Node *successor = findSuccessor(node);
    return successor ? successor->key : -1;
}

template <class T>
T AVLTree<T>::findPredecessor(T key)
{
    Node *node = search(root, key);
    if (node == nullptr) return -1;
    Node *predecessor = findPredecessor(node);
    return predecessor ? predecessor->key : -1;
}