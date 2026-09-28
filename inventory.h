#ifndef INVENTORY_H
#define INVENTORY_H

#include <string>
using namespace std;

const int MAX_PRODUCTS = 100;

struct Product
{
    string name;
    double price;
    int quantity;
};

void addRecord(Product products[], int& count);
void displayRecords(const Product products[], int count);
double calculateTotal(const Product products[], int count);

#endif