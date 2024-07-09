#include "bst.h"

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
    /*
                       50
                     /    \
                    30     70
                   /  \    /  \
                 20   40  60   80
    */
    // bst.inorderTraversal();
    // bst.delNode(80);
    // bst.inorderTraversal();
    // bst.height();
    // bst.postorderTraversal();
    // bst.preorderTraversal();
    // bst.preSec(50);
    // bst.isBst();
    // bst.Lca(30, 40);
    // bst.KthSmallestElement(5);
    // bst.CountNodesInRange(60, 80);
    // bst.CountAllNodes();
    // bst.Itpostorder();
    // bst.ItInorder();
    bst.reverselevelOrder();
    return 0;
}