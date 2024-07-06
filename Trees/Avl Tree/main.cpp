#include "avlTree.h"

int main()
{
    AVLTree<int> tree;
    int choice, key;
    do
    {
        cout << "\n------------------------ Menu ------------------------\n";
        cout << "1. Insert a node\n";
        cout << "2. Delete a node\n";
        cout << "3. Search for a node\n";
        cout << "4. Inorder traversal\n";
        cout << "5. Preorder traversal\n";
        cout << "6. Postorder traversal\n";
        cout << "7. Get height of the tree\n";
        cout << "8. Get diameter of the tree\n";
        cout << "9. Get minimum value\n";
        cout << "10. Get maximum value\n";
        cout << "11. Find successor of a node\n";
        cout << "12. Find predecessor of a node\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the key to insert: ";
            cin >> key;
            tree.insert(key);
            cout << "Inserted " << key << " into the tree.\n";
            break;
        case 2:
            cout << "Enter the key to delete: ";
            cin >> key;
            if (tree.search(key))
            {
                tree.remove(key);
                cout << "Deleted " << key << " from the tree.\n";
            }
            else cout << "Cannot delete because " << key << " does not exists.\n";
            break;
        case 3:
            cout << "Enter the key to search: ";
            cin >> key;
            if (tree.search(key)) cout << key << " found in the tree.\n";
            else cout << key << " not found in the tree.\n";
            break;
        case 4:
            cout << "Inorder traversal: ";
            tree.inorderTraversal();
            break;
        case 5:
            cout << "Preorder traversal: ";
            tree.preorderTraversal();
            break;
        case 6:
            cout << "Postorder traversal: ";
            tree.postorderTraversal();
            break;
        case 7:
            cout << "Height of the tree: " << tree.height() << endl;
            break;
        case 8:
            cout << "Diameter of the tree: " << tree.diameter() << endl;
            break;
        case 9:
            cout << "Minimum value: " << tree.findMin() << endl;
            break;
        case 10:
            cout << "Maximum value: " << tree.findMax() << endl;
            break;
        case 11:
            cout << "Enter the key to find its successor: ";
            cin >> key;
            cout << "Successor of " << key << " is " << tree.findSuccessor(key) << endl;
            break;
        case 12:
            cout << "Enter the key to find its predecessor: ";
            cin >> key;
            cout << "Predecessor of " << key << " is " << tree.findPredecessor(key) << endl;
            break;
        case 0:
            cout << "Exiting\n";
            break;
        default:
            cout << "Invalid choice Please try again\n";
        }
    } while (choice != 0);
    return 0;
}