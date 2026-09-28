#include <iostream>
#include <iomanip>
#include <limits>
#include "inventory.h"

using namespace std;

int main()
{
    Product products[MAX_PRODUCTS];
    int count = 0;
    int choice = 0;

    do
    {
        cout << "\n===== INVENTORY SYSTEM =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Products" << endl;
        cout << "3. Calculate Inventory Value" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Enter 1-4." << endl;
            continue;
        }

        switch (choice)
        {
            case 1:
                addRecord(products, count);
                break;

            case 2:
                displayRecords(products, count);
                break;

            case 3:
                cout << fixed << setprecision(2);
                cout << "Total Inventory Value: $"
                     << calculateTotal(products, count)
                     << endl;
                break;

            case 4:
                cout << "Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Enter 1-4."
                     << endl;
        }

    } while (choice != 4);

    return 0;
}