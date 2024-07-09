#include <iostream>
#include <stack>
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
    Node *insert(Node *node, int data);
    void inorder(Node *node);
    void postorder(Node *node);
    void preorder(Node *node);
    Node *minValueNode(Node *node);
    Node *deleteNode(Node *root, int data);
    int Height(Node* node);
    Node* search(Node* node, int data);
    Node* maxValueNode(Node* node);
    int diameter(Node* root);
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int data);
    bool isBST(Node* node);
    Node* lca(Node* root, int n1, int n2);
    void kthSmallestElement(Node *root, int k, int *arr, int &i);
    int getCount(Node *root, int low, int high);
    int countNodes(Node* root);
    void iterativePreorder(Node* root);
    void iterativePostorder(Node* root);
    void iterativeInorder(Node* root);
    void printLevelOrder(Node* root);
    void printCurrentLevel(Node* root, int level);
    void reverseLevelOrder(Node* root);

public:
    BST() : root(nullptr) {}
    void insert(int data);
    void inorderTraversal();
    void postorderTraversal();
    void preorderTraversal();
    void delNode(int data);
    void height();
    void Search(int data);
    void Diameter();
    void preSec(int data);
    void isBst();
    void Lca(int n1, int n2);
    void KthSmallestElement(int k);
    void CountAllNodes();
    void CountNodesInRange(int low, int high);
    void Itpreorder();
    void Itpostorder();
    void ItInorder();
    void levelOrder();
    void reverselevelOrder();
};

Node *BST::insert(Node *node, int data)
{
    if (node == nullptr) return new Node(data);
    if (data < node->data) node->left = insert(node->left, data);
    else if (data > node->data) node->right = insert(node->right, data);
    return node;
}
void BST::inorder(Node *node)
{
    if (node == nullptr) return;
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}
void BST::postorder(Node *node)
{
    if (node == nullptr) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->data << " ";
}
void BST::preorder(Node *node)
{
    if (node == nullptr) return;
    cout << node->data << " ";
    preorder(node->left);
    preorder(node->right);
}
Node *BST::minValueNode(Node *node)
{
    while (node && node->left != nullptr) node = node->left;
    return node;
}
Node *BST::deleteNode(Node *root, int data)
{
    if (root == nullptr) return root;
    if (data < root->data) root->left = deleteNode(root->left, data);
    else if (data > root->data) root->right = deleteNode(root->right, data);
    else
    {
        if (root->left == nullptr) // in case of right child
        {
            Node *temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) // in case of left child
        {
            Node *temp = root->left;
            delete root;
            return temp;
        }
        Node *temp = minValueNode(root->right); // in case of both childs
        root->data = temp->data; // swap with root
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}
int BST::Height(Node* node) 
{
    if (node == nullptr) return 0;
    int leftHeight = Height(node->left);
    int rightHeight = Height(node->right);
    return max(leftHeight, rightHeight) + 1;
}
Node* BST::search(Node* node, int data) 
{
    if (node == nullptr || node->data == data) return node;
    if (data < node->data) return search(node->left, data);
    else return search(node->right, data);
}
Node* BST::maxValueNode(Node* node) 
{
    while (node && node->right != nullptr) node = node->right;
    return node;
}
int BST::diameter(Node* root) 
{
    if (root == nullptr) return 0;
    int lh = Height(root->left);
    int rh = Height(root->right);
    int ld = diameter(root->left);
    int rd = diameter(root->right);
    return max(lh + rh + 1, max(ld, rd));
}
void BST::findPreSuc(Node* root, Node*& pre, Node*& suc, int data)
{
    if (root == NULL)  return;
    if (root->data == data)
    {
        if (root->left != NULL)
        {
            Node* tmp = root->left;
            while (tmp->right) tmp = tmp->right;
            pre = tmp ;
        }
        if (root->right != NULL)
        {
            Node* tmp = root->right ;
            while (tmp->left) tmp = tmp->left ;
            suc = tmp ;
        }
        return ;
    }
    if (root->data > data)
    {
        suc = root ;
        findPreSuc(root->left, pre, suc, data) ;
    }
    else
    {
        pre = root ;
        findPreSuc(root->right, pre, suc, data) ;
    }
}
bool BST::isBST(Node* node)
{
    if (node == NULL) return true;
    if (node->left != NULL && maxValueNode(node->left)->data >= node->data) return false;
    if (node->right != NULL && minValueNode(node->right)->data <= node->data) return false;
    if (!isBST(node->left) || !isBST(node->right)) return false;
    return true;
}

Node *BST::lca(Node *root, int n1, int n2)
{
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2) return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return lca(root->right, n1, n2);
    return root;
}

void BST::insert(int data)
{
    root = insert(root, data);
}

void BST::inorderTraversal()
{
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;
}

void BST::postorderTraversal()
{
    cout << "Postorder traversal: ";
    postorder(root);
    cout << endl;
}

void BST::preorderTraversal()
{
    cout << "Preorder traversal: ";
    preorder(root);
    cout << endl;
}

void BST::delNode(int data)
{
    root = deleteNode(root, data);
}

void BST::height()
{
    cout << "Height of bst is " << Height(root) << endl;
}

void BST::Search(int data)
{
    if(search(root,data)) cout << data << " found in bst" << endl;
    else cout << data << " not found" << endl;
}

void BST::Diameter()
{
    cout << "Diameter of bst is: " << diameter(root) << endl;
}

void BST::preSec(int data)
{
    Node* pre = NULL, *suc = NULL;
    findPreSuc(root, pre, suc, data);
    if (pre != NULL) cout << "Predecessor of " << data << " is " << pre->data << endl;
    else cout << "No Predecessor of " << data;
    if (suc != NULL) cout << "Successor of " << data << " is " << suc->data;
    else cout << "No Successor of " << data;
}

void BST::isBst()
{
    if(isBST(root)) cout << "Given binary tree is bst" << endl;
    else cout << "Given binary tree is not bst" << endl;
}

void BST::Lca(int n1, int n2)
{
    cout << "Least common ancesstor of " << n1 << " and " << n2 << " is " << lca(root, n1, n2)->data << endl;
}

void BST::KthSmallestElement(int k)
{
    int arr[7], i = 0;
    kthSmallestElement(root, k, arr, i);
    cout << k << "th smallest element is " << arr[k - 1] << endl;
}

void BST::CountAllNodes()
{
    cout << "Total number of nodes in bst are: " << countNodes(root) << endl;
}

void BST::CountNodesInRange(int low, int high)
{
    cout << "Total number of nodes in range [" << low << ", " << high << "] bst are: " << getCount(root, low, high) << endl;
}

void BST::Itpreorder()
{
    cout << "Pre order: ";
    iterativePreorder(root);
}

void BST::Itpostorder()
{
    cout << "Post order: ";
    iterativePostorder(root);
}

void BST::ItInorder()
{
    cout << "In order: ";
    iterativeInorder(root);
}

void BST::levelOrder()
{
    cout << "Level order: " << endl;
    printLevelOrder(root);
}

void BST::reverselevelOrder()
{
    cout << "Reverse Level order: " << endl;
    reverseLevelOrder(root);
}

void BST::kthSmallestElement(Node *root, int k, int* arr, int &i)
{
    if(root == nullptr) return;
    kthSmallestElement(root->left, k, arr, i);
    arr[i++] = root->data;
    kthSmallestElement(root->right, k, arr, i);
}

int BST::getCount(Node *root, int low, int high)
{
    if (!root) return 0;
    if (root->data == high && root->data == low) return 1;
    if (root->data <= high && root->data >= low) return 1 + getCount(root->left, low, high) + getCount(root->right, low, high);
    else if (root->data < low) return getCount(root->right, low, high);
    else return getCount(root->left, low, high);
}

int BST::countNodes(Node *root)
{
    if (root == nullptr) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void BST::iterativePreorder(Node *root)
{
    if (root == NULL) return;
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) 
    {
        Node* node = st.top();
        cout << node->data << " ";
        st.pop();
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
    }
}

void BST::iterativePostorder(Node *root)
{
    if (root == NULL) return;
    stack<Node*> st1, st2;
    st1.push(root);
    Node* node;
    while (!st1.empty()) 
    {
        node = st1.top();
        st1.pop();
        st2.push(node);
        if (node->left) st1.push(node->left);
        if (node->right) st1.push(node->right);
    }
    while (!st2.empty()) 
    {
        node = st2.top();
        st2.pop();
        cout << node->data << " ";
    }
}

void BST::iterativeInorder(Node *root)
{
    stack<Node*> st;
    Node* curr = root;
    while (curr != NULL || !st.empty()) 
    {
        while (curr != NULL) 
        {
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
}

void BST::printLevelOrder(Node *root)
{
    int h = Height(root);
    int i;
    for (i = 1; i <= h; i++) printCurrentLevel(root, i);
}

void BST::printCurrentLevel(Node *root, int level)
{
    if (root == NULL) return;
    if (level == 1) cout << root->data << " ";
    else if (level > 1) 
    {
        printCurrentLevel(root->left, level - 1);
        printCurrentLevel(root->right, level - 1);
    }
}

void BST::reverseLevelOrder(Node *root)
{ 
    int h = Height(root); 
    int i; 
    for (i=h; i>=1; i--) printCurrentLevel(root, i); 
} 