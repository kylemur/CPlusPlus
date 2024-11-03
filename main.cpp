#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Product {
private:
    string name;    
    double price;     
    int quantity;    
    double total_value;

public:
    Product(string name, double price, int quantity)
        : name(name), price(price), quantity(quantity), total_value(price * quantity) {}

    void setName(string n) { name = n; }
    void setPrice(double p) { price = p; }
    void setQuantity(int q) { quantity = q; }
    void setTotalValue() { total_value = price * quantity; }

    string getName() const { return name; }
    double getPrice() const { return price; }
    int getQuantity() const { return quantity; }
    double getTotalValue() const { return total_value; }

    void display() const { 
        cout << "\nName: " << name << endl;
        cout << "Price: $" << price << endl;
        cout << "Quantity: " << quantity << endl;
        cout << "Total Value: $" << total_value << endl << endl;
    }
};

class Inventory {
private:
    vector<unique_ptr<Product>> products;

public:
    ~Inventory() = default;

    void addProduct(unique_ptr<Product> product) {
        products.push_back(move(product));
    }

    void takeProduct(const string& productName, int quantity) {
        for (auto& product : products) {
            if (product->getName() == productName) {
                int current_quantity = product->getQuantity();
                if (quantity <= current_quantity) {
                    product->setQuantity(current_quantity - quantity);
                    product->setTotalValue();
                    cout << quantity << " " << productName << "(s) taken from inventory. New quantity: " << product->getQuantity() << endl;
                } else {
                    cout << "Invalid quantity.\n";
                }
                return;
            }
        }
        cout << "Product not found.\n";
    }

    void displayInventory() const {
        for (const auto& product : products) {
            product->display();
        }
        if (products.empty()) {
            cout << "Inventory is empty.\n";
        }
    }

    const vector<unique_ptr<Product>>& getProducts() const {
        return products;
    }

    Product* getProduct(const string& productName) const {
        for (const auto& product : products) {
            if (product->getName() == productName) {
                return product.get();
            }
        }
        return nullptr; // Return nullptr if product not found
    }

    double getTotalValue() const {
        double total = 0.0;
        for (const auto& product : products) {
            total += product->getTotalValue();
        }
        return total;
    }
};

int main(int argc, char const *argv[]) {
    Inventory inventory;

    string choice;
    do {
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

// 1. Display All Inventory
        if (choice == "1") {
            inventory.displayInventory();
            cout << "Total Value: $" << inventory.getTotalValue() << endl;
// 2. Search Inventory
        } else if (choice == "2") {
            cout << "  --------------------------\n";
            cout << "  Search Inventory\n";
            cout << "  --------------------------\n";
            cout << "  1. Search By Name\n";
            cout << "  2. Search By Price\n";
            cout << "  3. Search By Quantity\n";
            cout << "  Enter your choice: ";
            int search_choice;
            cin >> search_choice;
            cout << endl;

            bool product_found = false;

            if (search_choice == 1) { // Search By Name
                string search_name;
                cout << "Enter product name to search: ";
                cin >> search_name;

                for (const auto& product : inventory.getProducts()) {
                    if (product->getName() == search_name) {
                        product_found = true;
                        product->display();
                        break;
                    }
                }
            } else if (search_choice == 2) { // Search By Price
                double max_price;
                cout << "Enter max price to search: ";
                cin >> max_price;

                double min_price;
                cout << "Enter min price to search: ";
                cin >> min_price;

                for (const auto& product : inventory.getProducts()) {
                    if (product->getPrice() < max_price && product->getPrice() > min_price) {
                        product_found = true;
                        product->display();
                        break;
                    }
                }
            } else if (search_choice == 3) { // Search By Quantity
                int max_quantity;
                cout << "Enter max quantity to search: ";
                cin >> max_quantity;

                double min_quantity;
                cout << "Enter min quantity to search: ";
                cin >> min_quantity;

                for (const auto& product : inventory.getProducts()) {
                    if (product->getQuantity() < max_quantity && product->getQuantity() > min_quantity) {
                        product_found = true;
                        product->display();
                        break;
                    }
                }
            } else {
                cout << "Invalid choice.\n";
            }

            if (!product_found) {
                cout << "Product not found.\n";
            }
// 3. Add to Inventory
        } else if (choice == "3") {
            cout << "  --------------------------\n";
            cout << "  Add to Inventory\n";
            cout << "  --------------------------\n";
            cout << "  1. Add to Existing Product\n";
            cout << "  2. Add New Product\n";
            cout << "  Enter your choice: ";
            int add_choice;
            cin >> add_choice;
            cout << endl;

            if (add_choice == 1) { // Add to Existing Product
                string add_name;
                cout << "Enter product name to add: ";
                cin >> add_name;

                bool product_found = false;
                for (const auto& product : inventory.getProducts()) {
                    if (add_name == product->getName()) {
                        product_found = true;
                        int add_quantity;
                        cout << "Enter quantity to add: ";
                        cin >> add_quantity;
                        product->setQuantity(product->getQuantity() + add_quantity);
                        product->setTotalValue();
                        cout << add_quantity << " " << add_name << " added to inventory.\n";
                        break;
                    }
                }
                if (!product_found) {
                    cout << "Product not found.\n";
                }
            } else if (add_choice == 2) { // Add New Product
                string new_name;
                double new_price;
                int new_quantity;

                cout << "Enter product name: ";
                cin >> new_name;
                cout << "Enter product price: $";
                cin >> new_price;
                cout << "Enter product quantity: ";
                cin >> new_quantity;

                auto new_product = make_unique<Product>(new_name, new_price, new_quantity);
                new_product->display();
                inventory.addProduct(move(new_product));
                cout << "New product added to inventory.\n";
            } else {
                cout << "Invalid choice.\n";
            }
// 4. Take from Inventory
        } else if (choice == "4") {
            cout << "Take from Inventory\n";
            int take_quantity = 0;
            string take_name;
            cout << "Enter product name: ";
            cin >> take_name;
            
            Product* product = inventory.getProduct(take_name);
            if (product) {
                int current_quantity = product->getQuantity();
                cout << "Current quantity: " << current_quantity << endl;

                cout << "Enter quantity to take: ";
                cin >> take_quantity;
            }
            
            inventory.takeProduct(take_name, take_quantity);
// 5. Exit
        } else if (choice == "5") {
            cout << "Goodbye!\n";
        } else {
            cout << "Invalid choice.\n";
        }
    } while (choice != "5");

    return 0;
}