#include <iostream>
#include <stack>

using namespace std;

struct node
{
    int val;
    node *left;
    node *right;
    node(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator
{
private:
    stack<node *> nodeStack;
    void pushAllLeft(node *node)
    {
        while (node)
        {
            nodeStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(node *root)
    {
        pushAllLeft(root);
    }
    bool hasNext()
    {
        return !nodeStack.empty();
    }
    int next()
    {
        node *topNode = nodeStack.top();
        nodeStack.pop();
        if (topNode->right) pushAllLeft(topNode->right);
        return topNode->val;
    }
};

int main()
{
    node *root = new node(7);
    root->left = new node(3);
    root->right = new node(15);
    root->right->left = new node(9);
    root->right->right = new node(20);
    BSTIterator *iterator = new BSTIterator(root);
    while (iterator->hasNext()) cout << iterator->next() << " ";
    return 0;
}