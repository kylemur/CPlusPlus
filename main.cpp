#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
    int choice;
    do
    {
        cout << "\nMenu\n";
        cout << "----\n";
        cout << "1. Display All Inventory\n";
        cout << "2. Search Inventory\n";
        cout << "3. Add to Inventory\n";
        cout << "4. Take from Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    
        if (choice == 1)
        {
            cout << "Display All Inventory\n";
        }
        else if (choice == 2)
        {
            cout << "Search Inventory\n";
        }
        else if (choice == 3)
        {
            cout << "Add to Inventory\n";
        }
        else if (choice == 4)
        {
            cout << "Take from Inventory\n";
        }
        else
        {
            cout << "Goodbye!\n";
        }
    } while (choice != 5);

    return 0;
}