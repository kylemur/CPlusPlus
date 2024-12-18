#include <iostream>
using namespace std;   // if only using 1 namespace, can leave out   std::   in all code

struct InventoryItem {
    string name;
    double price;
    int quantity;

    void display() {   
        cout << "Name: " << name << endl;
        cout << "Price: " << price << endl;
        cout << "Quantity: " << quantity << endl;
    }
};

/*
int main(int argc, char const *argv[])
{
    int nice_number = 69;
    // std::cout << "Hello World!\n";
    // std::cout << nice_number;
    
    std::cout << "Hello World!" << std::endl << nice_number; // same as above

    return 0;
}
*/

int main(int argc, char const *argv[])
{
    int nice_number = 69;
    // cout << "Hello World!\n";
    // cout << nice_number;
    cout << "Hello World!\n" << nice_number << endl; // same as above


    int fav_number;
    cout << "Enter your favorite number: ";
    cin >> fav_number;
    cout << "Your favorite number is: " << fav_number << endl;


    int me = 28, you = 30;
    if (me > you)
    {
        cout << "I am older than you" << endl;
    }
    else if (me == you)
    {
        cout << "We are the same age" << endl;
    }
    else
    {
        cout << "You are older than me" << endl;
    }

    InventoryItem item1;
    item1.name = "Widget";
    item1.price = 1;
    item1.quantity = 100;
    item1.display();

    return 0;
}