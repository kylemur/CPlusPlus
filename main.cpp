#include <iostream>
#include <vector>
using namespace std;


class Product {
private:
    string name;    
    double price;     
    int quantity;    
    double total_value;

public:
    void setName(string n) { 
        name = n; 
        }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void setTotalValue() { total_value = price * quantity; }

    string getName() { 
        return name; 
        }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }
    double getTotalValue() { return total_value; }

    void display() { 
        setTotalValue();
        cout << "Name: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: $" << total_value << endl << endl;
    }
};


int main(int argc, char const *argv[])
{
    vector<Product> inventory;

    int choice;
    do
    {
        cout << "\nMenu\n";
        cout << "------------------------\n";
        cout << "1. Display All Inventory\n";
        cout << "2. Search Inventory\n";
        cout << "3. Add to Inventory\n";
        cout << "4. Take from Inventory\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cout << endl;
    
        // Display All Inventory
        if (choice == 1) 
        {
            double inventory_value = 0;
            
            if (!inventory.empty())
            {
                for (int i = 0; i < inventory.size(); i++)
                {
                    inventory[i].display();
                }
            }
            else
            {
                cout << "Inventory is empty.\n";
            }

            for (int i = 0; i < inventory.size(); i++)
            {
                inventory_value += inventory[i].getTotalValue();
            }
            cout << "Inventory Value: $" << inventory_value << endl;
        }

        // Search Inventory
        else if (choice == 2) 
        {
            cout << "  --------------------\n";
            cout << "  Search Inventory\n";
            cout << "  --------------------\n";
            cout << "  1. Search by name\n";
            cout << "  2. Search by price\n";
            cout << "  3. Search by quantity\n";
            cout << "  Enter your choice: ";
            int search_choice;
            cin >> search_choice;
            cout << endl;
    
            if (search_choice == 1) // Search by name
            {
                string search_name;
                cout << "Enter product name to search: ";
                cin >> search_name;

                bool product_found = false;
                for (int i = 0; i < inventory.size(); i++) {
                    if (search_name == inventory[i].getName()) {
                        product_found = true;
                        inventory[i].display();
                        break;
                    }
                }
                if (!product_found) {
                    cout << "Product not found.\n";
                }
            }
            else if (search_choice == 2) // Search by price
            {
                double search_price_max;
                double search_price_min;
                cout << "Enter max product price: $";
                cin >> search_price_max;
                cout << "Enter min product price: $";
                cin >> search_price_min;

                bool product_found = false;
                for (int i = 0; i < inventory.size(); i++)
                {
                    if (inventory[i].getPrice() <= search_price_max && inventory[i].getPrice() >= search_price_min)
                    {
                        product_found = true;
                        inventory[i].display();
                        break;
                    }
                }
                if (!product_found)
                {
                    cout << "No products found.\n";
                }
            }
            else if (search_choice == 3) // Search by quantity
            {
                int search_quantity_max;
                int search_quantity_min;
                cout << "Enter max product quantity: ";
                cin >> search_quantity_max;
                cout << "Enter min product quantity: ";
                cin >> search_quantity_min;

                bool product_found = false;
                for (int i = 0; i < inventory.size(); i++)
                {
                    if (inventory[i].getPrice() <= search_quantity_max && inventory[i].getPrice() >= search_quantity_min)
                    {
                        product_found = true;
                        inventory[i].display();
                        break;
                    }
                }
                if (!product_found)
                {
                    cout << "No products found.\n";
                }
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }

        // Add to Inventory
        else if (choice == 3) 
        {
            cout << "  --------------------------\n";
            cout << "  Add to Inventory\n";
            cout << "  --------------------------\n";
            cout << "  1. Add to Existing Product\n";
            cout << "  2. Add New Product\n";
            cout << "  Enter your choice: ";
            int add_choice;
            cin >> add_choice;
            cout << endl;

            if (add_choice == 1) // Add to Existing Product
            {
                string add_name;
                cout << "Enter product name to add: ";
                cin >> add_name;

                bool product_found = false;
                for (int i = 0; i < inventory.size(); i++) {
                    if (add_name == inventory[i].getName()) {
                        product_found = true;
                        int add_quantity;

                        cout << "Current quantity: " << inventory[i].getQuantity() << endl;
                        cout << "Enter quantity to add: ";
                        cin >> add_quantity;

                        inventory[i].setQuantity(inventory[i].getQuantity() + add_quantity);
                        cout << add_quantity << " " << add_name << "(s) added to inventory.\n";
                       
                        inventory[i].display();
                        break; // Exit the loop once the product is found and updated
                    }
                }
                if (!product_found) {
                    cout << "Product not found.\n";
                }
            }
            else if (add_choice == 2) // Add New Product
            {
                Product product1;
                string p_name;
                double p_price;
                int p_quantity;

                cout << "Enter product name: ";
                cin >> p_name;
                product1.setName(p_name);

                cout << "Enter product price: $";
                cin >> p_price;
                product1.setPrice(p_price);

                cout << "Enter product quantity: ";
                cin >> p_quantity;
                product1.setQuantity(p_quantity);

                product1.setTotalValue();
                cout << "Total Value: $" << product1.getTotalValue() << endl;

                inventory.push_back(product1);
                cout << p_quantity << " " << p_name << "(s) added to inventory.\n";
            }
            else
            {
                cout << "Invalid choice.\n";
            }
        }

        // Take from Inventory
        else if (choice == 4) 
        {
            int take_quantity;
            string take_name;
            cout << "Enter product name: ";
            cin >> take_name;

            bool product_found = false;

            for (auto& product : inventory) {  // auto& finds correct object (product) in vector (inventory)
                if (product.getName() == take_name) {
                    product_found = true;
                    int current_quantity = product.getQuantity();
                    cout << "Current quantity: " << current_quantity << endl;
                    cout << "Enter quantity to take: ";
                    cin >> take_quantity;

                    if (take_quantity <= current_quantity) {
                        int new_quantity = current_quantity - take_quantity;
                        product.setQuantity(new_quantity);
                        cout << take_quantity << " " << take_name << "(s) taken from inventory. New quantity: " << new_quantity << endl;
                    } else {
                        cout << "Invalid quantity.\n";
                    }
                    break;
                }
            }
            if (product_found == false) {
                cout << "Product not found.\n";
            }
        }

        // Exit
        else if (choice == 5) 
        {
            cout << "Goodbye!\n";
        }

        else
        {
            cout << "Invalid choice.\n";
        }
    } while (choice != 5);

    return 0;
}