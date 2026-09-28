#include <iostream>
#include <iomanip>
#include <limits>
#include "inventory.h"

using namespace std;

void addRecord(Product products[], int& count)
{
    if (count >= MAX_PRODUCTS)
    {
        cout << "Inventory is full!" << endl;
        return;
    }

    Product newProduct;

    cout << "Enter product name: ";
    getline(cin >> ws, newProduct.name);

    cout << "Enter product price: ";
    while (!(cin >> newProduct.price) || newProduct.price < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid price: ";
    }

    cout << "Enter quantity: ";
    while (!(cin >> newProduct.quantity) || newProduct.quantity < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter a valid quantity: ";
    }

    products[count] = newProduct;
    count++;

    cout << "Product added successfully!" << endl;
}

void displayRecords(const Product products[], int count)
{
    cout << "\n===== INVENTORY RECORDS =====" << endl;

    if (count == 0)
    {
        cout << "No products available." << endl;
        return;
    }

    cout << fixed << setprecision(2);

    for (int i = 0; i < count; i++)
    {
        cout << "\nProduct " << i + 1 << endl;
        cout << "Name: " << products[i].name << endl;
        cout << "Price: $" << products[i].price << endl;
        cout << "Quantity: " << products[i].quantity << endl;
    }
}

double calculateTotal(const Product products[], int count)
{
    double total = 0;

    for (int i = 0; i < count; i++)
    {
        total += products[i].price * products[i].quantity;
    }

    return total;
}