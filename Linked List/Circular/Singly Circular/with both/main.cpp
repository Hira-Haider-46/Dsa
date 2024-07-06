#include"LinkedList.h"
int main()
{
    LinkedList<int> list;
    int choice;
    do {
        cout << "\n1. Insert data at end\n"
            << "2. Delete data from end\n"
            << "3. Insert data at head\n"
            << "4. Delete data from head\n"
            << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
        {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertAtEnd(val);
            list.display();
            break;
        }
        case 2:
            list.deleteFromEnd();
            list.display();
            break;
        case 3: {
            int val;
            cout << "Enter value to insert: ";
            cin >> val;
            list.insertAtHead(val);
            list.display();
            break;
        }
        case 4:
            list.deleteFromHead();
            list.display();
            break;
        case 5:
            cout << "Exiting program" << endl;
            break;
        default:
            cout << "Invalid choice Please try again" << endl;
        }
    } while (choice != 5);
    return 0;
}